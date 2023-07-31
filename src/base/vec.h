//
// Created by daniel on 26/07/23.
//

#ifndef GEOMETRICALGORITHMS_VEC_H
#define GEOMETRICALGORITHMS_VEC_H

#include <array>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include "core.h"


namespace jmk {

    constexpr std::size_t DIM2 {2};
    constexpr std::size_t DIM3 {3};

    template<typename coordinate_type, std::size_t dimension = DIM3>
    class Vector {
    private:

        static_assert(std::is_arithmetic<coordinate_type>::value, "Vector can only store Integer or Double");
        static_assert(dimension >= 2, "Vector should have at least two dimensions");

        std::array<coordinate_type, dimension> m_coords;

    public:

        Vector() = default;

        Vector(coordinate_type x, coordinate_type y)
                : m_coords {x, y}
        {

        }

        Vector(coordinate_type x, coordinate_type y, coordinate_type z)
            : m_coords {x, y, z}
        {

        }

        Vector(std::initializer_list<coordinate_type> coords) {
            if (coords.size() != dimension) {
                throw std::invalid_argument("Incorrect number of elements for Vector initialization");
            }
            std::copy(coords.begin(), coords.end(), m_coords.begin());
        }

        [[nodiscard]] double magnitude() const {
            double sum {0.0};
            for (auto ii {0}; ii < m_coords.size(); ++ii){
                sum += m_coords[ii] * m_coords[ii];
            }
            return std::sqrt(sum);
        }

        [[nodiscard]] std::size_t getDimensionality() const { return m_coords.size(); }

        coordinate_type X() const { return m_coords[0]; }
        coordinate_type Y() const { return m_coords[1]; }
        coordinate_type Z() const { return m_coords[2]; }

        // Comparison operators

        friend bool operator==(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            return vec1.m_coords == vec2.m_coords;
        }

        friend bool operator!=(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            return vec1.m_coords != vec2.m_coords;
        }

        friend bool operator>(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            for (auto ii {0}; ii < vec1.getDimensionality(); ++ii){
                if (vec1.m_coords[ii] > vec2.m_coords[ii])
                    return true;
                else if (vec1.m_coords[ii] < vec2.m_coords[ii])
                    return false;
            }
            return false;
        }

        friend bool operator<(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            for (auto ii {0}; ii < vec1.getDimensionality(); ++ii){
                if (vec1.m_coords[ii] < vec2.m_coords[ii])
                    return true;
                else if (vec1.m_coords[ii] > vec2.m_coords[ii])
                    return false;
            }
            return false;
        }

        // Arithmetic operators

        friend Vector<coordinate_type, dimension> operator+(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            Vector<coordinate_type, dimension> newVec;
            for (auto ii {0}; ii < vec1.getDimensionality(); ++ii){
                newVec.m_coords[ii] = vec1.m_coords[ii] + vec2.m_coords[ii];
            }
            return newVec;
        }

        friend Vector<coordinate_type, dimension> operator-(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            Vector<coordinate_type, dimension> newVec;
            for (auto ii {0}; ii < vec1.getDimensionality(); ++ii){
                newVec.m_coords[ii] = vec1.m_coords[ii] - vec2.m_coords[ii];
            }
            return newVec;
        }

        friend Vector<coordinate_type, dimension> operator*(
                const Vector<coordinate_type, dimension>& vec,
                coordinate_type scalar){
            // Multiply the vector by a scalar
            Vector<coordinate_type, dimension> newVec;
            for (auto ii {0}; ii < vec.getDimensionality(); ++ii){
                newVec.m_coords[ii] = vec.m_coords[ii] * scalar;
            }
            return newVec;
        }

        // [] Operator
        coordinate_type& operator[] (std::size_t index){
            return m_coords[index];
        }

        coordinate_type operator[] (std::size_t index) const {
            return m_coords[index];
        }

        // IO operators

        friend std::ostream& operator<< (
                std::ostream& out,
                const Vector<coordinate_type, dimension>& vec
                ){
            out << "Vector(";
            std::size_t dims {vec.getDimensionality()};
            if (dims < 10){
                for (auto ii {0}; ii < dims - 1; ++ii){
                    out << vec.m_coords[ii] << ", ";
                }
                out << vec.m_coords[dims - 1];
            }
            else {
                // Print the first 5 elements and the last 5
                for (auto ii {0}; ii < 5; ++ii){
                    out << vec.m_coords[ii] << ", ";
                }
                out << "... ";
                for (auto ii {dims - 5}; ii > dims - 1; --ii){
                    out << vec.m_coords[ii] << ", ";
                }
                out << vec.m_coords[dims - 1];
            }
            out << ")";
            return out;
        }

    };

    template <std::size_t dimension>
    bool operator==(
            const Vector<double, dimension>& vec1,
            const Vector<double, dimension>& vec2
            ){
        return isEqualD(vec1.m_coords, vec2.m_coords);
    }

    template <std::size_t dimension>
    bool operator!=(
            const Vector<double, dimension>& vec1,
            const Vector<double, dimension>& vec2
    ){
        return !isEqualD(vec1.m_coords, vec2.m_coords);
    }

    // Products
    template<typename coordinate_type, std::size_t dimension>
    double dotProduct(
            const Vector<coordinate_type, dimension>& vec1,
            const Vector<coordinate_type, dimension>& vec2
            ){
        coordinate_type product {0};
        for (auto ii {0}; ii < vec1.getDimensionality(); ++ii){
            product += vec1[ii] * vec2[ii];
        }
        return product;
    }

    template <std::size_t dimension>
    void normalize(Vector<double, dimension>& vec) {
        double mag {vec.magnitude()};
        for (auto ii {0}; ii < vec.getDimensionality(); ++ii){
            vec[ii] /= mag;
        }
    }

    typedef Vector<double, DIM2> Vector2f;
    typedef Vector<double, DIM3> Vector3f;

    double crossProduct2D(const Vector2f &vec1, const Vector2f &vec2);
    Vector3f crossProduct3D(const Vector3f &vec1, const Vector3f & vec2);

}

#endif //GEOMETRICALGORITHMS_VEC_H
