//
// Created by daniel on 26/07/23.
//

#include "vec.h"


double jmk::crossProduct2D(const jmk::Vector2f &vec1, const jmk::Vector2f &vec2)
{
    return vec1.X() * vec2.Y() - vec2.X() * vec1.Y();
}

jmk::Vector3f jmk::crossProduct3D(const jmk::Vector3f &vec1, const jmk::Vector3f &vec2)
{
    double x {vec1.Y() * vec2.Z() - vec2.Y() * vec1.Z()};
    double y {vec2.X() * vec1.Z() - vec1.X() * vec2.Z()};
    double z {vec1.X() * vec2.Y() - vec2.X() * vec1.Y()};
    return {x, y, z};
}
