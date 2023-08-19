//
// Created by daniel on 31/07/23.
//

#include "geoutils.h"

double jmk::areaTriangle3D(
        const jmk::Point3d &origin,
        const jmk::Point3d &destination,
        const jmk::Point3d &point) {
    // vector from origin to destination
    Vector3f OD {destination - origin};
    // vector from destination to point
    Vector3f OP {point - origin};
    Vector3f cross{crossProduct3D(OD, OP)};

    double sumOfPowers {
        std::pow(cross.X(), 2) +
        std::pow(cross.Y(), 2) +
        std::pow(cross.Z(), 2)
    };
    return std::sqrt(sumOfPowers) / 2;
}

jmk::RelativePosition jmk::orientation3d(
        const Point3d& origin,
        const Point3d& destination,
        const Point3d& point){
    // Predicate to determine the orientation of the given point
    // with respect to the segment [origin, destination]
    if (point == origin)
        return jmk::RelativePosition::ORIGIN;
    if (point == destination)
        return jmk::RelativePosition::DESTINATION;

    double area {areaTriangle3D(origin, destination, point)};

    if (std::abs(area) < TOLERANCE || area == 0)
        area = 0;

    if (area > 0)
        return jmk::RelativePosition::LEFT;
    if (area < 0)
        // Does it even make sense to have left or right in 3D?
        // It depends on the observer
        return jmk::RelativePosition::RIGHT;

    // Point is on the same line

    // vector from origin to destination
    Vector3f OD {destination - origin};
    // vector from destination to point
    Vector3f OP {point - origin};
    // Check if the vector OP is in the opposite direction. Meaning
    // that at least one of its coordinates changed sign
    if (OD.X() * OP.X() < 0 || OD.Y() * OP.Y() < 0)
        return jmk::RelativePosition::BEHIND;
    // If the magnitude of OP is greater, it is beyond
    if (OP.magnitude() > OD.magnitude())
        return jmk::RelativePosition::BEYOND;
    // Point must be between
    return jmk::RelativePosition::BETWEEN;
}


double jmk::areaTriangle2D(
        const jmk::Point2d &origin,
        const jmk::Point2d &destination,
        const jmk::Point2d &point) {
    // vector from origin to destination
    Vector2f OD {destination - origin};
    // vector from destination to point
    Vector2f OP {point - origin};
    return crossProduct2D(OD, OP) / 2;
}

jmk::RelativePosition jmk::orientation2d(
        const Point2d& origin,
        const Point2d& destination,
        const Point2d& point){
    // Predicate to determine the orientation of the given point
    // with respect to the segment [origin, destination]
    if (point == origin)
        return jmk::RelativePosition::ORIGIN;
    if (point == destination)
        return jmk::RelativePosition::DESTINATION;

    // vector from origin to destination
    Vector2f OD {destination - origin};
    // vector from destination to point
    Vector2f OP {point - origin};
    double area {crossProduct2D(OD, OP) / 2};

    if (std::abs(area) < TOLERANCE || area == 0)
        area = 0;

    if (area > 0)
        return jmk::RelativePosition::LEFT;
    if (area < 0)
        return jmk::RelativePosition::RIGHT;

    // Point is on the same line

    // Check if the vector OP is in the opposite direction. Meaning
    // that at least one of its coordinates changed sign
    if (OD.X() * OP.X() < 0 || OD.Y() * OP.Y() < 0)
        return jmk::RelativePosition::BEHIND;
    // If the magnitude of OP is greater, it is beyond
    if (OP.magnitude() > OD.magnitude())
        return jmk::RelativePosition::BEYOND;
    // Point must be between
    return jmk::RelativePosition::BETWEEN;
}
