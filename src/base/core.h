//
// Created by daniel on 26/07/23.
//

#ifndef GEOMETRICALGORITHMS_CORE_H
#define GEOMETRICALGORITHMS_CORE_H

#include <array>
#include <cmath>

namespace jmk {

    constexpr double TOLERANCE {0.0000000001};

    bool isEqualD(double num1, double num2, double tolerance = TOLERANCE);

    template<std::size_t dim>
    bool isEqualD(const std::array<double, dim>& arr1,
                  const std::array<double, dim>& arr2,
                  double tolerance = TOLERANCE){
        for (auto ii {0}; ii < arr1.size(); ++ii) {
            if (!isEqualD(arr1[ii], arr2[ii], tolerance)){
                return false;
            }
        }
        return true;
    }
}

#endif //GEOMETRICALGORITHMS_CORE_H
