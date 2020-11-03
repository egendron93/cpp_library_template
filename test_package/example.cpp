/**
 * @file example.cpp
 * @author Edwin Gendron
 * @date 2020-07-05
 */

#include <iostream>

#include <hello_world.hpp>

int main(int argc, char** argv) {
    std::cout << hello::GetHelloWorldString() << std::endl;
    return 0;
}
