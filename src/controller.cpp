#include "controller.hpp"

tvtennis::controller::controller(){
    _map.clear();
}

void tvtennis::controller::map_control( input input, control control ){
   _map[input] = control;
}

std::vector<tvtennis::control> tvtennis::controller::read_inputs() {

   std::vector<control> controls;
   controls.clear();

    SDL_Event event;

    while ( SDL_PollEvent(&event) ){
        switch ( event.type ){
            case SDL_QUIT:
                controls.push_back(tvtennis::control::quit);
                break;
        }
    }

   return controls;
}