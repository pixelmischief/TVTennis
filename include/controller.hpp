#ifndef TVT_CONTROLLER_H
#define TVT_CONTROLLER_H

#include <vector>
#include <map>
#include <SDL2/SDL.h>

namespace tvtennis {

    enum input {
        key_w = SDLK_w,
        key_s = SDLK_s,
        key_arrow_up = SDLK_UP,
        key_arrow_down = SDLK_DOWN,
        key_escape = SDLK_ESCAPE,
        mouse_move_up,
        mouse_move_down,
        mouse_btn_left,
        mouse_btn_right
    };

    enum control {
        quit,
        escape,
        pause,
        p1_up,
        p1_down,
        p2_up,
        p2_down
    };

    class controller {
        protected:
        std::map<input, control> _map;

        public:
        controller();
        void map_control( input, control );
        std::vector<control> read_inputs();

    };

}


#endif