cmake_minimum_required(VERSION 3.10)

find_package(Boost 1.85.0 REQUIRED)
find_package(Microsoft.GSL 4.0.0 REQUIRED)

add_library(hello_world 
    hello_world.cpp
    string_reversal.cpp
)

set(HELLO_WORLD_HEADERS
    ${CMAKE_SOURCE_DIR}/include/hello_world.hpp
    ${CMAKE_SOURCE_DIR}/include/string_reversal.hpp
)

set_target_properties(hello_world PROPERTIES PUBLIC_HEADER 
    "${HELLO_WORLD_HEADERS}"
)

target_include_directories(hello_world PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(hello_world PUBLIC cxx_std_20)

target_link_libraries(hello_world PUBLIC 
    boost::boost
    Microsoft.GSL::GSL
)

install(TARGETS hello_world)

add_library(hello_world::hello_world ALIAS hello_world)