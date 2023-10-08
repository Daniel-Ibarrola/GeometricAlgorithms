//
// Created by daniel on 7/10/23.
//

#include "intersection.h"


bool isInLine(jmk::RelativePosition& orientation){
    return orientation == jmk::RelativePosition::ORIGIN
        || orientation == jmk::RelativePosition::DESTINATION
        || orientation == jmk::RelativePosition::BETWEEN;
}


bool jmk::lineIntersection(const jmk::Point2d &l1_a, const jmk::Point2d &l1_b,
                           const jmk::Point2d &l2_c, const jmk::Point2d &l2_d) {
    // Check if two lines segments intersect.
    // l1_a and l1_b are the endpoints of line 1
    // l2_c and l2_d are the endpoints of line 2

    // Orientation of a and c with respect to line 2
    auto orientation_a {orientation2d(l2_c, l2_d, l1_a)};
    auto orientation_b {orientation2d(l2_c, l2_d, l1_b)};
    // Orientation of c and d with respect to line 1
    auto orientation_c {orientation2d(l1_a, l1_b, l2_c)};
    auto orientation_d {orientation2d(l1_a, l1_b, l2_d)};

    if (isInLine(orientation_a) || isInLine(orientation_b)
        || isInLine(orientation_c) || isInLine(orientation_d))
        return true;

    return _xor(orientation_a == RelativePosition::LEFT,orientation_b == RelativePosition::LEFT)
        && _xor(orientation_c == RelativePosition::LEFT,orientation_d == RelativePosition::LEFT);
}


jmk::Point2d jmk::intersectionPoint(
        const jmk::Point2d &l1_a, const jmk::Point2d &l1_b,
        const jmk::Point2d &l2_c, const jmk::Point2d &l2_d) {
    // Calculate the intersection point of two lines. Will throw an
    // error if they cannot intersect
    // l1_a and l1_b are the endpoints of line 1
    // l2_c and l2_d are the endpoints of line 2

    Vector2f AB {l1_b - l1_a};
    Vector2f CD {l2_d - l2_c};

    Vector2f normal {CD.Y(), -CD.X()};
    auto denominator {dotProduct(normal, AB)};

    if (isEqualD(denominator, 0.0)){
        throw std::logic_error("Lines do not intersect");
    }

    Vector2f AC {l2_c - l1_a};
    auto numerator {dotProduct(normal, AC)};
    auto quotient {numerator / denominator};
    auto xCoord = l1_a.X() + quotient * AB.X();
    auto yCoord = l1_a.Y() + quotient * AB.Y();

    return {xCoord, yCoord};
}