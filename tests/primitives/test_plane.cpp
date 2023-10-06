//
// Created by daniel on 5/10/23.
//
#include "gtest/gtest.h"
#include "point.h"
#include "plane.h"


TEST(PlaneFromThreePoints, HasCorrectNormalAndConstant)
{
    jmk::Point3d p1 {1, -2, 1};
    jmk::Point3d p2 {4, -2, -2};
    jmk::Point3d p3 {4, 1, 4};
    jmk::Plane plane {p1, p2, p3};

    jmk::Vector3f expectedNormal {9, -18, 9};
    double expectedConstant {54};
    ASSERT_EQ(plane.getNormal(), expectedNormal);
    ASSERT_EQ(plane.getConstant(), expectedConstant);
}
