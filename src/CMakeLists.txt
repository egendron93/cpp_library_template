cmake_minimum_required(VERSION 3.10)

find_package(Boost 1.73.0 REQUIRED)
find_package(Microsoft.GSL 3.1.0 REQUIRED)

add_library(hello_world 
    hello_world.cpp
    string_reversal.cpp
)

target_include_directories(hello_world PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(hello_world PUBLIC cxx_std_20)

target_link_libraries(hello_world PUBLIC 
    Boost::Boost
    Microsoft.GSL::Microsoft.GSL
)

include(CheckIPOSupported)
check_ipo_supported()
set_property(TARGET hello_world PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)

add_library(hello_world::hello_world ALIAS hello_world)