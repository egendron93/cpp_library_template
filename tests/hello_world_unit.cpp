/**
 * @file hello_world_unit.cpp
 * @author Edwin Gendron
 * @date 2020-07-01
 */

#include <gtest/gtest.h>

#include <hello_world.hpp>

using namespace hello;

TEST(HelloWorldUnit, GetHelloWorldString_ReturnsHelloWorld) {
    ASSERT_EQ("hello world", GetHelloWorldString());
}
