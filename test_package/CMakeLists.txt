cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(hello_world CONFIG REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example hello_world::hello_world)

target_compile_features(example PUBLIC cxx_std_20)

add_test(NAME example.test_package
    COMMAND example
)