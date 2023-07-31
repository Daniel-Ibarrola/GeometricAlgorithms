//
// Created by daniel on 30/07/23.
//
#include "gtest/gtest.h"
#include "core.h"


TEST(TestCore, NumbersWithSmallDifferenceConsideredEqual)
{
    double num1 {0.0051};
    double num2 {0.005};

    ASSERT_TRUE(jmk::isEqualD(num1, num2, 0.002));
}


TEST(TestCore, NumbersWithBiggerDifferenceNotConsideredEqual)
{
    double num1 {0.0051};
    double num2 {0.006};

    ASSERT_TRUE(jmk::isEqualD(num1, num2, 0.002));
}


TEST(TestCore, EqualityOfArrayOfDoubles)
{
    std::array<double, 2> arr1 {0.0005, 0.1};
    std::array<double, 2> arr2 {0.00051, 0.1};

    ASSERT_TRUE(jmk::isEqualD(arr1, arr2, 0.002));
}
