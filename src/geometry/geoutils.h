//
// Created by daniel on 31/07/23.
//

#ifndef GEOMETRICALGORITHMS_GEOUTILS_H
#define GEOMETRICALGORITHMS_GEOUTILS_H

#include "../base/core.h"
#include "../primitives/point.h"

namespace jmk {

    RelativePosition orientation3d(
            const Point3d& origin,
            const Point3d& destination,
            const Point3d& point
            );
    RelativePosition orientation2d(
            const Point2d& origin,
            const Point2d& destination,
            const Point2d& point
            );
}

#endif //GEOMETRICALGORITHMS_GEOUTILS_H
