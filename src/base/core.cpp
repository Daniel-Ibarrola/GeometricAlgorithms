//
// Created by daniel on 26/07/23.
//

#include "core.h"


bool jmk::isEqualD(double num1, double num2, double tolerance){
    return std::abs(num1 - num2) < tolerance;
}
