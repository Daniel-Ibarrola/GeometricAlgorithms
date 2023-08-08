//
// Created by daniel on 31/07/23.
//
#include "gtest/gtest.h"
#include "geoutils.h"


// Relative Position in 3D

TEST(TestRelativePostion2D, PointToTheRightOfSegment)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(3., 2.);

    jmk::RelativePosition orientation {
        jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::RIGHT);
}


TEST(TestRelativePostion2D, PointToTheLeftOfSegment)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(1., 1.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::LEFT);
}


TEST(TestRelativePostion2D, PointBetweenSegment)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(2., 1.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BETWEEN);
}


TEST(TestRelativePostion2D, PointBehindSegment)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(4., -1.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BEHIND);
}


TEST(TestRelativePostion2D, PointBeyondSegment)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(-1., 4.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BEYOND);
}


TEST(TestRelativePostion2D, PointInOrigin)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(3., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::ORIGIN);
}


TEST(TestRelativePostion2D, PointInDestination)
{
    jmk::Point2d origin(3., 0.);
    jmk::Point2d destination(0., 3.);
    jmk::Point2d testPoint(0., 3.);

    jmk::RelativePosition orientation {
            jmk::orientation2d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::DESTINATION);
}

// Relative Position in 3D

TEST(TestRelativePostion3D, PointToTheRightOfSegment)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(3., 2., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::RIGHT);
}


TEST(TestRelativePostion3D, PointToTheLeftOfSegment)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(1., 1., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::LEFT);
}


TEST(TestRelativePostion3D, PointBetweenSegment)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(2., 1., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BETWEEN);
}


TEST(TestRelativePostion3D, PointBehindSegment)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(4., -1., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BEHIND);
}


TEST(TestRelativePostion3D, PointBeyondSegment)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(-1., 4., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::BEYOND);
}


TEST(TestRelativePostion3D, PointInOrigin)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(3., 0., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::ORIGIN);
}


TEST(TestRelativePostion3D, PointInDestination)
{
    jmk::Point3d origin(3., 0., 0.);
    jmk::Point3d destination(0., 3., 0.);
    jmk::Point3d testPoint(0., 3., 0.);

    jmk::RelativePosition orientation {
            jmk::orientation3d(origin, destination, testPoint)};
    ASSERT_EQ(orientation, jmk::RelativePosition::DESTINATION);
}
