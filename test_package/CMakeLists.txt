cmake_minimum_required(VERSION 3.10)
project(hello_world_test_package)

if(NOT TARGET hello_world::hello_world) 
    find_package(hello_world REQUIRED)
endif()

enable_testing()
add_executable(example
    example.cpp
)

target_compile_features(example PUBLIC cxx_std_20)

target_link_libraries(example PUBLIC 
    hello_world::hello_world
)

include(CheckIPOSupported)
check_ipo_supported()
set_property(TARGET example PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

add_test(NAME example.test_package
    COMMAND example
)