#ifndef TVT_BODY_H
#define TVT_BODY_H

#include "vector2f.hpp"
#include "color.hpp"

namespace tvtennis {

    struct body {
        vector2f position;
        vector2f dimension;
        vector2f velocity;
        tvtennis::color color;
        bool is_fixture; 
    };
}

#endif