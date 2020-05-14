#ifndef TVT_SCREEN_H
#define TVT_SCREEN_H

#include <SDL2/SDL.h>
#include "vector2f.hpp"
#include "color.hpp"
#include "world.hpp"

namespace tvtennis {

    class screen {
        private:
        vector2f _dimension;
        bool _is_full_screen;
        SDL_Renderer* _render_target;
        SDL_Window* _window;

        public:
        screen( const vector2f, const bool );
        ~screen();
        bool initialize();
        void render( const color, const world );
    };
}

#endif
