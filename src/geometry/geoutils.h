//
// Created by daniel on 31/07/23.
//

#ifndef GEOMETRICALGORITHMS_GEOUTILS_H
#define GEOMETRICALGORITHMS_GEOUTILS_H

#include <cmath>
#include "../base/core.h"
#include "../primitives/point.h"

namespace jmk {

    double areaTriangle3D(
            const Point3d& origin,
            const Point3d& destination,
            const Point3d& point
            );
    RelativePosition orientation3d(
            const Point3d& origin,
            const Point3d& destination,
            const Point3d& point
            );

    double areaTriangle2D(
            const Point2d& origin,
            const Point2d& destination,
            const Point2d& point
            );
    RelativePosition orientation2d(
            const Point2d& origin,
            const Point2d& destination,
            const Point2d& point
            );
}

#endif //GEOMETRICALGORITHMS_GEOUTILS_H
