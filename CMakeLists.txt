cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ENABLE_TESTING OFF CACHE BOOL "Add the tests subdirectory to the build.")

add_subdirectory(src)

message("${ENABLE_TESTING}")

if(ENABLE_TESTING)
    add_subdirectory(test)
endif()
