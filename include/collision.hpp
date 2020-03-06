#ifndef TVT_COLLISION_H
#define TVT_COLLISION_H

#include "body.hpp"

namespace tvtennis {

    struct collision {
        body* a;
        body* b;
    };

}

#endif