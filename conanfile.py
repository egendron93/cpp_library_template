from conans import ConanFile, CMake
from conan.tools.google import Bazel

class HelloWorldConan(ConanFile):
  name = "hello_world"
  version = "0.0.0"
  url = ""
  settings = "os", "compiler", "build_type", "arch"
  #generators = {"cmake_find_package", "BazelDeps", "BazelToolchain"}
  generators = {"BazelDeps", "BazelToolchain"}
  options = {"enable_testing":[True, False]}
  default_options = {"enable_testing": False}
  exports_sources = {"src/**", "tests/**", "CMakeLists.txt"}

  def requirements(self):
    self.requires.add("boost/1.73.0")
    if self.options.enable_testing:
      self.requires.add("gtest/1.8.1")

  def build(self):
    # cmake = CMake(self)
    # cmake.definitions["ENABLE_TESTING"] = "ON" if self.options.enable_testing else "OFF"
    # cmake.configure()
    # cmake.build()
    bazel = Bazel(self)
    bazel.configure()
    bazel.build(label="//...")

  def package(self):
    self.copy("*.hpp", dst="include/", src="src/include/")
    self.copy("*.so", dst="lib", keep_path=False)
    self.copy("*.a", dst="lib", keep_path=False)
  
  def package_info(self):
    self.cpp_info.libs = ["hello_world"]