#ifndef TVT_MENU_H
#define TVT_MENU_H

#include "mode.hpp"
#include "menu_item.hpp"

namespace tvtennis {

    class menu : mode {

        public:
        std::vector<tvtennis::menu_item> menu_items;

        menu();
        ~menu();

        void process ( const float time, const std::vector<input> inputs );
        void display ( const screen* p_screen );

    };

}

#endif