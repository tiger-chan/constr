#
# ConStr
#

cmake_minimum_required(VERSION 3.12.4)

#
# Project version
#

## TODO: Pull from cpp file
set (CONSTR_VERSION "0.1.0")

project(
	constr
	VERSION ${CONSTR_VERSION}
	DESCRIPTION "Small C++ lib for constexpr string"
	HOMEPAGE_URL "https://github.com/tiger-chan/constr"
	LANGUAGES CXX
)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

#
# Add Targets
#

option(CONSTR_INCLUDE_HEADERS "Add all ConStr headers to the ConStr target." OFF)

include(GNUInstallDirs)

add_library(
	constr
	STATIC
		$<BUILD_INTERFACE:${constr_SOURCE_DIR}/src/constr/string_view.cpp>
		$<BUILD_INTERFACE:${constr_SOURCE_DIR}/src/constr/string.cpp>
)
add_library(constr::constr ALIAS constr)

target_include_directories(
	constr
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(constr PUBLIC cxx_std_17)

if (CONSTR_INCLUDE_HEADERS)
	target_sources(
		constr
		STATIC
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/config/macro.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/config/version.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/constr.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/fwd.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_algo.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_fixed.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_fixed.inl>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_util.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_util.inl>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_view.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string_view.inl>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/include/constr/string.hpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/src/constr/string_view.cpp>
			$<BUILD_INTERFACE:${constr_SOURCE_DIR}/src/constr/string.cpp>
	)
endif()

#
# Install constr
#

include(CMakePackageConfigHelpers)

install(
	TARGETS constr
	EXPORT constrTargets
		ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

install(
	DIRECTORY include/constr src/constr ${PROJECT_BINARY_DIR}/include/constr
	DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
	FILES_MATCHING
		PATTERN "*.h"
		PATTERN "*.hpp"
		PATTERN "*.inl"
)

write_basic_package_version_file(
	constrConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
	${constr_SOURCE_DIR}/cmake/in/constrConfig.cmake.in
    constrConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/constr/cmake
)

export(
	EXPORT constrTargets
	FILE ${CMAKE_CURRENT_BINARY_DIR}/constrTargets.cmake
	NAMESPACE constr::
)

install(
    EXPORT constrTargets
    FILE constrTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/constr/cmake
    NAMESPACE constr::
)

install(
    FILES
        ${PROJECT_BINARY_DIR}/constrConfig.cmake
        ${PROJECT_BINARY_DIR}/constrConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/constr/cmake
)

install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(PACKAGE constr)

#
# Tests
#

option(CONSTR_BUILD_TESTING "Enable building tests." OFF)

if(CONSTR_BUILD_TESTING)
	option(CONSTR_FIND_GTEST_PACKAGE "Enable finding gtest package." OFF)

	set(CONSTR_CXX_STD cxx_std_17 CACHE STRING "C++ standard revision to use for the tests")

	include(CTest)
	enable_testing()
	add_subdirectory(test)
endif()
