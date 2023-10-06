//
// Created by daniel on 5/10/23.
//

#ifndef GEOMETRICALGORITHMS_PLANE_H
#define GEOMETRICALGORITHMS_PLANE_H

#include "../base/vec.h"
#include "point.h"

namespace jmk {

    class Plane {
    private:
        Vector3f m_normal {};
        double m_constant {0};

    public:

        Plane() = default;

        Plane(Vector3f& normal, double constant) : m_normal {normal}, m_constant {constant} {}

        Plane(Point3d& p1, Point3d& p2, Point3d p3) {
            // Calculate two vectors in the plane
            auto v12 {p2 - p1};
            auto v13 {p3 - p1};
            m_normal = crossProduct3D(v12, v13);
            m_constant = dotProduct(m_normal, p1);
        }

        [[nodiscard]] Vector3f getNormal() const { return m_normal; }
        [[nodiscard]] double getConstant() const { return m_constant; }

    };
}



#endif //GEOMETRICALGORITHMS_PLANE_H
