//
// Created by daniel on 26/07/23.
//

#ifndef GEOMETRICALGORITHMS_VEC_H
#define GEOMETRICALGORITHMS_VEC_H

#include <array>
#include <initializer_list>
#include <stdexcept>


namespace jmk {

    constexpr std::size_t DIM2 {2};
    constexpr std::size_t DIM3 {3};

//    constexpr std::size_t X {0};
//    constexpr std::size_t Y {1};
//    constexpr std::size_t Z {2};

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
                throw std::invalid_argument("Incorrect number if elements for Vector initialization");
            }
            std::copy(coords.begin(), coords.end(), m_coords.begin());
        }

        void normalize() {

        }

        coordinate_type magnitude() const {
            return {};
        }

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
            return false;
        }

        friend bool operator<(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            return true;
        }

        friend Vector<coordinate_type, dimension> operator+(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            return {};
        }

        friend Vector<coordinate_type, dimension> operator-(
                const Vector<coordinate_type, dimension>& vec1,
                const Vector<coordinate_type, dimension>& vec2){
            return {};
        }

    };

    typedef Vector<double, DIM2> Vector2f;
    typedef Vector<double, DIM3> Vector3f;

//    // Comparison operators
//    template<typename coordinate_type, std::size_t dimension>
//    bool operator== (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return vec1.m_coords == vec2.m_coords;
//    }
//
//    template<typename coordinate_type, std::size_t dimension>
//    bool operator!= (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return vec1.m_coords != vec2.m_coords;
//    }
//
//    template<typename coordinate_type, std::size_t dimension>
//    bool operator< (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return false;
//    }
//
//    template<typename coordinate_type, std::size_t dimension>
//    bool operator> (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return false;
//    }
//
//    // Arithmetic operators
//    template<typename coordinate_type, std::size_t dimension>
//    Vector<coordinate_type, dimension> operator+ (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return {};
//    }
//
//    template<typename coordinate_type, std::size_t dimension>
//    Vector<coordinate_type, dimension> operator- (
//            const Vector<coordinate_type, dimension>& vec1,
//            const Vector<coordinate_type, dimension>& vec2)
//    {
//        return {};
//    }

    // Products
    template<typename coordinate_type, std::size_t dimension>
    double dotProduct(
            const Vector<coordinate_type, dimension>& vec1,
            const Vector<coordinate_type, dimension>& vec2
            ){
        return 0.;
    }

    double crossProduct2D(const Vector2f &vec1, const Vector2f &vec2);
    Vector3f crossProduct3D(const Vector3f &vec1, const Vector3f & vec3);

}

#endif //GEOMETRICALGORITHMS_VEC_H
