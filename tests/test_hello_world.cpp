//
// Created by daniel on 26/07/23.
//
#include "gtest/gtest.h"


TEST(TestHelloWorld, HelloWorld)
{
    std::string str {"hello world"};
    ASSERT_EQ(str, "hello world");
}
