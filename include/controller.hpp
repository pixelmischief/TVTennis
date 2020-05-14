#ifndef TVT_CONTROLLER_H
#define TVT_CONTROLLER_H

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "input.hpp"
#include "control.hpp"

namespace tvtennis {
    class controller {
        protected:
            std::map<input, control> _map;
        public:
            controller();
            void map_control(input, control);
            std::vector<control> read_inputs();
    };
}

#endif