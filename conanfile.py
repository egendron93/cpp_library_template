from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps

class helloWorldRecipe(ConanFile):
    name = "hello_world"
    version = "1.0.0"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False], "enable_testing": [True, False]}
    default_options = {"shared": False, "fPIC": True, "enable_testing": False}

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("boost/1.85.0")
        self.requires("ms-gsl/4.0.0")
    
    def build_requirements(self):
        self.test_requires("gtest/1.14.0")

    def generate(self):
        cmake = CMakeDeps(self)
        cmake.generate()
        tc = CMakeToolchain(self)
        tc.variables["ENABLE_TESTING"] = "ON" if self.options.enable_testing else "OFF"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["hello_world"]
