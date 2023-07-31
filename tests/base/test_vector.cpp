//
// Created by daniel on 26/07/23.
//
#include "gtest/gtest.h"
#include "vec.h"


TEST(VectorTest, CanAddTwoVectors)
{
    jmk::Vector<int, 4> vec1 {1, 2, 3, 4};
    jmk::Vector<int, 4> vec2 {5, 6, 7, 8};

    jmk::Vector<int, 4> result {vec1 + vec2};

    jmk::Vector<int, 4> expectedSum {6, 8, 10, 12};
    ASSERT_EQ(result, expectedSum);
}


TEST(VectorTest, CanSubstractTwoVectors)
{
    jmk::Vector<int, 4> vec1 {1, 2, 3, 4};
    jmk::Vector<int, 4> vec2 {5, 6, 7, 8};

    jmk::Vector<int, 4> result {vec2 - vec1};

    jmk::Vector<int, 4> expectedDiff {4, 4, 4, 4};
    ASSERT_EQ(result, expectedDiff);
}


TEST(VectorTest, MultiplyByScalar)
{
    jmk::Vector3f vec (1., 2., 3.);
    jmk::Vector3f result{vec * 5};
    jmk::Vector3f expected(5., 10., 15.);
    ASSERT_EQ(result, expected);
}


TEST(VectorTest, GreaterThanComparison)
{
    jmk::Vector<int, 4> vec1 {1, 2, 3, 4};
    jmk::Vector<int, 4> vec2 {5, 6, 7, 8};

    ASSERT_TRUE(vec2 > vec1);
}


TEST(VectorTest, LessThanComparison)
{
    jmk::Vector<int, 4> vec1 {1, 2, 3, 4};
    jmk::Vector<int, 4> vec2 {5, 6, 7, 8};

    ASSERT_TRUE(vec1 < vec2);
}


TEST(VectorTest, DotProduct)
{
    jmk::Vector<double, 3> vec1 {1., 2., 3.};
    jmk::Vector<double, 3> vec2 {4., 5., 6.};

    double product {jmk::dotProduct(vec1, vec2)};
    ASSERT_EQ(product, 32);
}


TEST(VectorTest, CrossProduct2D)
{
    jmk::Vector2f vec1 (1., 2.);
    jmk::Vector2f vec2 (3., 4.);

    double product {jmk::crossProduct2D(vec1, vec2)};
    ASSERT_EQ(product, -2.);
}


TEST(VectorTest, CrossProduct3D)
{
    jmk::Vector3f vec1 (5., 6., 2.);
    jmk::Vector3f vec2 (1., 1., 1.);

    jmk::Vector3f result {jmk::crossProduct3D(vec1, vec2)};

    jmk::Vector3f expected (4., -3., -1.);
    ASSERT_EQ(result, expected);
}


TEST(VectorTest, Magnitude)
{
    jmk::Vector2f vec1 (4., 3.);
    ASSERT_EQ(vec1.magnitude(), 5.);
}


TEST(VectorTest, Normalize)
{
    jmk::Vector2f vec (4., 3.);
    jmk::normalize(vec);

    jmk::Vector2f expected (4./ 5., 3. / 5.);
    ASSERT_EQ(vec, expected);
}


TEST(VectorTest, GetItem)
{
    jmk::Vector2f vec (4., 3.);
    double x{vec[0]};
    ASSERT_EQ(x, 4.);
}


TEST(VectorTest, SetItem)
{
    jmk::Vector2f vec (4., 3.);
    vec[0] = 5.;
    ASSERT_EQ(vec[0], 5.);
}