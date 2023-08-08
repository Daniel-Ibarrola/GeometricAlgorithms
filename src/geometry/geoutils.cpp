//
// Created by daniel on 31/07/23.
//

#include "geoutils.h"

jmk::RelativePosition jmk::orientation3d(
        const Point3d& origin,
        const Point3d& destination,
        const Point3d& point){
    // Predicate to determine the orientation of the given point
    // with respect to the segment [origin, destination]
    return jmk::RelativePosition::BEHIND;
}


jmk::RelativePosition jmk::orientation2d(
        const Point2d& origin,
        const Point2d& destination,
        const Point2d& point){
    // Predicate to determine the orientation of the given point
    // with respect to the segment [origin, destination]
    return jmk::RelativePosition::BEHIND;
}
