#
# Tests configuration
#

include(FetchContent)
include(CheckCXXSourceCompiles)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if (CONSTR_FIND_GTEST_PACKAGE)
	find_package(GTest REQUIRED)
else()
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG main
		GIT_SHALLOW 1
	)

	FetchContent_GetProperties(googletest)

	if(NOT googletest_POPULATED)
		FetchContent_Populate(googletest)
		set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
		add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
	endif()

	add_library(GTest::Main ALIAS gtest_main)

	target_compile_features(gtest PUBLIC cxx_std_17)
	target_compile_features(gtest_main PUBLIC cxx_std_17)
	target_compile_features(gmock PUBLIC cxx_std_17)
	target_compile_features(gmock_main PUBLIC cxx_std_17)
endif()

include_directories($<TARGET_PROPERTY:constr,INTERFACE_INCLUDE_DIRECTORIES>)
add_compile_options($<TARGET_PROPERTY:constr,INTERFACE_COMPILE_OPTIONS>)

function(SETUP_TARGET TARGET_NAME)
    set_target_properties(${TARGET_NAME} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${TARGET_NAME} PRIVATE ${CONSTR_CXX_STD})
    target_link_libraries(${TARGET_NAME} PRIVATE constr)

    if(MSVC)
        target_compile_options(
            ${TARGET_NAME}
            PRIVATE
                /EHsc /W1 /wd4996 /w14800
                $<$<CONFIG:Debug>:/Od>
                $<$<CONFIG:Release>:/O2>
        )
    else()
        target_compile_options(
            ${TARGET_NAME}
            PRIVATE
                -pedantic -fvisibility=hidden -Wall -Wshadow -Wno-deprecated-declarations
                $<$<CONFIG:Debug>:-O0 -g>
                $<$<CONFIG:Release>:-O2>
        )
    endif()

    target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
            _ENABLE_EXTENDED_ALIGNED_STORAGE
            NOMINMAX
            ${ARGN}
    )
endfunction()

add_library(test_lib OBJECT test_lib.cpp)
SETUP_TARGET(test_lib)

function(SETUP_BASIC_TEST TEST_NAME TEST_SOURCES)
    add_executable(${TEST_NAME} $<TARGET_OBJECTS:test_lib> ${TEST_SOURCES})
    target_link_libraries(${TEST_NAME} PRIVATE GTest::Main Threads::Threads)
    SETUP_TARGET(${TEST_NAME} ${ARGN})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

#
# Test config
#

SETUP_BASIC_TEST(String constr/string.cpp)