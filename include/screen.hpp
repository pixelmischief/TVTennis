#ifndef TVT_SCREEN_H
#define TVT_SCREEN_H

#include <SDL2/SDL.h>
#include "vector.hpp"
#include "color.hpp"
#include "world.hpp"

namespace tvtennis {

    class screen {
        private:
        tvtennis::vector _dimension;
        bool _is_full_screen;
        SDL_Renderer* _render_target;
        SDL_Window* _window;

        public:
        screen( const tvtennis::vector, const bool );
        ~screen();
        bool initialize();
        void render( const tvtennis::color, const tvtennis::world );
    };
}

#endif
