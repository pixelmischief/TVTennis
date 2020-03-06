#ifndef TVT_BODY_H
#define TVT_BODY_H

#include "vector.hpp"
#include "color.hpp"

namespace tvtennis {

    struct body {
        vector position;
        vector dimension;
        vector velocity;
        color color;
        bool is_fixture; 
    };
}

#endif