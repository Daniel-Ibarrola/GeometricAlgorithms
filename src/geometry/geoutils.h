//
// Created by daniel on 31/07/23.
//

#ifndef GEOMETRICALGORITHMS_GEOUTILS_H
#define GEOMETRICALGORITHMS_GEOUTILS_H

#include "../primitives/point.h"

namespace jmk {

    int orientation3d(const Point3d& a, const Point3d& b, const Point3d& c);
    int orientation2d(const Point2d& a, const Point2d& b, const Point2d& c);

}

#endif //GEOMETRICALGORITHMS_GEOUTILS_H
