cmake_minimum_required(VERSION 3.10)
project(hello_world VERSION 0.0.0)

set(ENABLE_TESTING "Add the tests subdirectory to the build." OFF)

add_subdirectory(src)

if(ENABLE_TESTING)
    add_subdirectory(tests)
endif()
