from mimetypes import suffix_map
from conans import ConanFile, CMake, tools
import os
import shutil


class ConStrConan(ConanFile):
    name = "constr"
    version = "0.1.0"
    license = "MIT"
    author = "Anthony Young <anthony.r.young@gmail.com>"
    url = "https://github.com/tiger-chan/constr"
    homepage = url
    description = "Small C++ lib for constexpr string"
    topics = ("string")
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "build_tests": [True, False]
    }

    default_options = {
        "shared": False,
        "fPIC": True,
        "build_tests": False
    }

    generators = "cmake"

    no_copy_source = True

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            del self.options.fPIC

    def export_sources(self):
        self.copy("LICENSE")
        self.copy("CMakeLists.txt")
        folders = ["cmake", "include", "src", "test"]
        for folder in folders:
            shutil.copytree(folder, os.path.join(
                self.export_sources_folder, folder))

    def package_id(self):
        del self.info.options.build_tests

    def build(self):
        cmake = CMake(self)

        #cmake.verbose = True

        cmake.definitions["CONSTR_BUILD_TESTING"] = self.options.build_tests
        cmake.configure()
        cmake.build()
        if self.options.build_tests:
            cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["constr"]

        self.cpp_info.names["cmake_find_package"] = "constr"
        self.cpp_info.names["cmake_find_package_multi"] = "constr"
