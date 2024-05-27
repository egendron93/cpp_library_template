cmake_minimum_required(VERSION 3.10)

enable_testing()
find_package(GTest 1.14.0 REQUIRED)

if(NOT TARGET hello_world::hello_world)
    find_package(hello_world CONFIG REQUIRED)
endif()

add_executable(hello_world_unit
    hello_world_unit.cpp
    string_reversal_unit.cpp
    main.cpp
)

target_compile_features(hello_world_unit PUBLIC cxx_std_20)

target_link_libraries(hello_world_unit PUBLIC 
    hello_world::hello_world
    gtest::gtest
)

add_test(NAME hello_world.unit
    COMMAND hello_world_unit
)