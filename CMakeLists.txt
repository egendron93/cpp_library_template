cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

if (NOT BUILD_TESTING STREQUAL OFF)
    add_subdirectory(tests)
endif()
