//
// Created by daniel on 5/10/23.
//

#ifndef GEOMETRICALGORITHMS_LINE_H
#define GEOMETRICALGORITHMS_LINE_H

#include "../base/vec.h"

namespace jmk {

    template<class coord_type, std::size_t dim = DIM3>
    class Line {
    private:

        Vector<coord_type, dim> point;
        Vector<coord_type, dim> dir;

    public:

        Line() = default;

        Line(Vector<coord_type, dim>& p1, Vector<coord_type, dim>& p2) {
            dir = p2 - p1;
            point = p1;
        }

        Vector<coord_type, dim> getPoint() const { return  point; }
        Vector<coord_type, dim> getDir() const { return dir; }

    };

}

#endif //GEOMETRICALGORITHMS_LINE_H
