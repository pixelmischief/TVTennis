#ifndef TVT_GAME_H
#define TVT_GAME_H

#include "mode.hpp"
#include "menu_item.hpp"
#include "utility.hpp"
#include "color.hpp"
#include "world.hpp"
#include "body.hpp"
#include "controller.hpp"
#include "configuration.hpp"

namespace tvtennis {



    class game : mode {

        private:
        world world;
        body ball;
        body racket_left;
        body racket_right;
        body wall_left;
        body wall_right;
        body wall_top;
        body wall_bottom;
        controller controller;


        public:
        std::vector<tvtennis::menu_item> menu_items;

        game();
        ~game();

        void process ( const float time, const std::vector<input> inputs );
        void display ( const screen* p_screen );

    };

}

#endif