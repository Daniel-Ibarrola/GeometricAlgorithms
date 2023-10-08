//
// Created by daniel on 7/10/23.
//

#ifndef GEOMETRICALGORITHMS_INTERSECTION_H
#define GEOMETRICALGORITHMS_INTERSECTION_H

#include "geoutils.h"

namespace jmk {

    bool lineIntersection(
            const Point2d& l1_a, const Point2d& l1_b,
            const Point2d& l2_c, const Point2d& l2_d
            );

    Point2d intersectionPoint(
            const Point2d& l1_a, const Point2d& l1_b,
            const Point2d& l2_c, const Point2d& l2_d
    );

}

#endif //GEOMETRICALGORITHMS_INTERSECTION_H
