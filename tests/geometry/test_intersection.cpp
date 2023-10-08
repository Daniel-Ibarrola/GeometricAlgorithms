//
// Created by daniel on 7/10/23.
//

#include "gtest/gtest.h"
#include "intersection.h"


TEST(DoLineSegementsIntersect, SimpleIntersection){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0, 1};
    jmk::Point2d p4 {1, 0};
    ASSERT_TRUE(jmk::lineIntersection(p1, p2, p3, p4));
}


TEST(DoLineSegementsIntersect, EndpointOnInteresction){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0.5, 0.5};
    jmk::Point2d p4 {1, 0};
    ASSERT_TRUE(jmk::lineIntersection(p1, p2, p3, p4));
}


TEST(DoLineSegementsIntersect, LinesShareEndpoints){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0, 0};
    jmk::Point2d p4 {1, 0};
    ASSERT_TRUE(jmk::lineIntersection(p1, p2, p3, p4));
}


TEST(DoLineSegementsIntersect, NoIntersection){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {0, 1};
    // Second line points
    jmk::Point2d p3 {1, 0};
    jmk::Point2d p4 {1, 1};
    ASSERT_FALSE(jmk::lineIntersection(p1, p2, p3, p4));
}


TEST(LineIntersectionPoint, SimpleIntersection){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0, 1};
    jmk::Point2d p4 {1, 0};

    jmk::Point2d intersection {jmk::intersectionPoint(p1, p2, p3, p4)};
    jmk::Point2d expected {0.5, 0.5};
    ASSERT_EQ(intersection, expected);
}


TEST(LineIntersectionPoint, EndpointOnInteresction){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0.5, 0.5};
    jmk::Point2d p4 {1, 0};

    jmk::Point2d intersection {jmk::intersectionPoint(p1, p2, p3, p4)};
    jmk::Point2d expected {0.5, 0.5};
    ASSERT_EQ(intersection, expected);
}


TEST(LineIntersectionPoint, LinesShareEndpoints){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {1, 1};
    // Second line points
    jmk::Point2d p3 {0, 0};
    jmk::Point2d p4 {1, 0};

    jmk::Point2d intersection {jmk::intersectionPoint(p1, p2, p3, p4)};
    jmk::Point2d expected {0., 0.};
    ASSERT_EQ(intersection, expected);
}


TEST(LineIntersectionPoint, NoIntersectionThrowsError){
    // First line points
    jmk::Point2d p1 {0, 0};
    jmk::Point2d p2 {0, 1};
    // Second line points
    jmk::Point2d p3 {1, 0};
    jmk::Point2d p4 {1, 1};
    EXPECT_THROW(jmk::intersectionPoint(p1, p2, p3, p4), std::logic_error);
}