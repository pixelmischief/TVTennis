#ifndef TVT_WORLD_H
#define TVT_WORLD_H

#include <vector>
#include "body.hpp"
#include "collision.hpp"

namespace tvtennis {

    class world {

        public:
        std::vector<tvtennis::body*> p_bodies;
        tvtennis::vector2f dimension;

        world();
        void tick(const float);
        bool detect_collision(const tvtennis::body*, const tvtennis::body*);
    };
}

#endif