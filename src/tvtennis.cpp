#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <math.h>
#include "utility.hpp"
#include "configuration.hpp"
#include "world.hpp"
#include "body.hpp"
#include "vector2f.hpp"
#include "controller.hpp"
#include "screen.hpp"
#include "game.hpp"

using namespace tvtennis;

const float SCREEN_REFRESH_TICK = 1.0f / SCREEN_FRAMES_PER_SECOND;
const vector2f SCALE = { SCREEN_WIDTH / WORLD_WIDTH, SCREEN_HEIGHT / WORLD_HEIGHT };


int main(int argc, char *args[]){

    //Initialize Display
    vector2f dimension;
    dimension.x = SCREEN_WIDTH;
    dimension.y = SCREEN_HEIGHT;
    screen* screen = new tvtennis::screen( dimension, SCREEN_IS_FULL_SCREEN );
    if ( screen->initialize() == false ){
        std::cout << "Could not initialize display.  Exiting." << std::endl;;
        return RETURN_ERROR;
    }

    //Initialize Clock
    std::chrono::steady_clock clock;
    float delta_time = ZERO;
    std::chrono::steady_clock::time_point last_tick = clock.now();
    std::chrono::steady_clock::time_point this_tick;

    //Initialize Modes
    mode* current_mode;
    game* game = new tvtennis::game();
    //current_mode = (mode*)game;


    // //Initialize Input
    // controller controller;
    // //controller.map_control(input::key_escape, control::quit);
    // //controller.map_control(input::key_w, control::p1_up);
    // //controller.map_control(input::key_s, control::p1_down);


    // //Enter Game Loop
    // bool quit_bit = false;
    // while ( quit_bit == false ){

    //     this_tick = clock.now();
    //     std::chrono::duration<float> time_since_last_tick = this_tick - last_tick;
    //     delta_time += time_since_last_tick.count();
    //     last_tick = this_tick;

    //     std::vector<control> inputs = controller.read_inputs();
    //     for ( int index = 0 ; index < inputs.size() ; index++ ){
    //         if ( inputs[index] == control::quit ){
    //             quit_bit = true;
    //         }
    //     }

    //     while ( delta_time >= ( SCREEN_REFRESH_TICK ) ){

    //         //current_mode->process(SCREEN_REFRESH_TICK, inputs)

    //         delta_time -= SCREEN_REFRESH_TICK;
    //     }

    //     //Render World
    //     //screen->render( COLOR_BLACK, world );
    // }
    
    // delete screen;
    // return RETURN_OK;
    return 0;
}


