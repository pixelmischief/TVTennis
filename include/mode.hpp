#ifndef TVT_MODE_H
#define TVT_MODE_H

#include <vector>
#include <string>

#include "state.hpp"
#include "input.hpp"
#include "screen.hpp"


namespace tvtennis {

    class mode {

        public:
        state state;
        std::vector<std::string> controls;

        virtual void process ( const float, const std::vector<input> ) = 0;
        virtual void display ( const screen* ) = 0;

    };

}

#endif
