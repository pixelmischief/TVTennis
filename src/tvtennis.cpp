#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <math.h>
#include "world.hpp"
#include "body.hpp"
#include "screen.hpp"
#include "controller.hpp"

//Return
const int RETURN_OK = 0;
const int RETURN_ERROR = 1;

//Utility
const float UTILITY_ZERO = 0.0f;
const float UTILITY_FACTOR_HALF = 0.5f;
const float UTILITY_FACTOR_DOUBLE = 2.0f;
const float UTILITY_FACTOR_TRIPLE = 3.0f;
const float UTILITY_FACTOR_FOUR = 4.0f;
const float UTILITY_FACTOR_FIVE = 5.0;
const float UTILITY_FACTOR_EIGHT = 8.0;
const float UTILITY_FACTOR_TEN = 10.0;
const float UTILITY_FACTOR_FIFTEEN = 15.0;
const float UTILITY_FACTOR_TWENTY = 20.0;
const float UTILITY_FACTOR_INVERT = -1.0f;

//World
const float WORLD_UNIT = 1.0f;
const float WORLD_WIDTH = 80.0f;
const float WORLD_HEIGHT = 60.0f;
const float WORLD_SLOW_MOTION_FACTOR = UTILITY_FACTOR_TEN;

//Fixtures
const float FIXTURE_BALL_DIMENSIONS = WORLD_UNIT;
const float FIXTURE_BALL_MIN_VELOCITY_X = WORLD_UNIT * UTILITY_FACTOR_TWENTY;
const float FIXTURE_BALL_MAX_VELOCITY_X = FIXTURE_BALL_MIN_VELOCITY_X * UTILITY_FACTOR_FOUR;
const float FIXTURE_RACKET_WIDTH = WORLD_UNIT;
const float FIXTURE_RACKET_HEIGHT = FIXTURE_RACKET_WIDTH * UTILITY_FACTOR_FIVE;
const float FIXTURE_RACKET_SPACING = FIXTURE_RACKET_WIDTH * UTILITY_FACTOR_FOUR;
const float FIXTURE_WALL_THICKNESS = WORLD_UNIT;

//Screen
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;
const bool SCREEN_IS_FULL_SCREEN = false;
const float SCREEN_FRAMES_PER_SECOND = 60.0f;
const tvtennis::vector SCREEN_SCALE = { SCREEN_WIDTH / WORLD_WIDTH, SCREEN_HEIGHT / WORLD_HEIGHT };
const float SCREEN_REFRESH_TICK = 1.0f / SCREEN_FRAMES_PER_SECOND;
const tvtennis::color SCREEN_COLOR_TERMINALGREEN = { 64, 192, 64, 255 };
const tvtennis::color SCREEN_COLOR_BLACK = { 0, 0, 0, 255 };





int main(int argc, char *args[]){

    tvtennis::world world;
    world.dimension = { WORLD_WIDTH, WORLD_HEIGHT };

    //Ball
    tvtennis::body ball;
    ball.dimension = { FIXTURE_BALL_DIMENSIONS, FIXTURE_BALL_DIMENSIONS };
    ball.position = { WORLD_WIDTH * UTILITY_FACTOR_HALF, WORLD_HEIGHT * UTILITY_FACTOR_HALF };
    ball.velocity = { FIXTURE_BALL_MIN_VELOCITY_X * UTILITY_FACTOR_INVERT, UTILITY_ZERO };
    ball.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&ball);

    //Rackets
    tvtennis::body racket_left;
    racket_left.dimension = { FIXTURE_RACKET_WIDTH, FIXTURE_RACKET_HEIGHT };
    racket_left.position = { FIXTURE_RACKET_SPACING, ( WORLD_HEIGHT * UTILITY_FACTOR_HALF ) - ( FIXTURE_RACKET_HEIGHT * UTILITY_FACTOR_HALF ) };
    racket_left.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    racket_left.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&racket_left);

    tvtennis::body racket_right;
    racket_right.dimension = { FIXTURE_RACKET_WIDTH, FIXTURE_RACKET_HEIGHT };
    racket_right.position = { WORLD_WIDTH - FIXTURE_RACKET_SPACING - FIXTURE_RACKET_WIDTH, ( WORLD_HEIGHT * UTILITY_FACTOR_HALF ) - ( FIXTURE_RACKET_HEIGHT * UTILITY_FACTOR_HALF ) };
    racket_right.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    racket_right.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&racket_right);

    //Walls
    tvtennis::body wall_left;
    wall_left.dimension = { FIXTURE_WALL_THICKNESS, WORLD_HEIGHT };
    wall_left.position = { UTILITY_ZERO, UTILITY_ZERO };
    wall_left.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    wall_left.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&wall_left);

    tvtennis::body wall_right;
    wall_right.dimension = { FIXTURE_WALL_THICKNESS, WORLD_HEIGHT };
    wall_right.position = { ( WORLD_WIDTH - WORLD_UNIT ), UTILITY_ZERO };
    wall_right.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    wall_right.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&wall_right);

    tvtennis::body wall_top;
    wall_top.dimension = { WORLD_WIDTH, FIXTURE_WALL_THICKNESS };
    wall_top.position = { UTILITY_ZERO, UTILITY_ZERO };
    wall_top.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    wall_top.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&wall_top);

    tvtennis::body wall_bottom;
    wall_bottom.dimension = { WORLD_WIDTH, FIXTURE_WALL_THICKNESS };
    wall_bottom.position = { UTILITY_ZERO, WORLD_HEIGHT - WORLD_UNIT };
    wall_bottom.velocity = { UTILITY_ZERO, UTILITY_ZERO };
    wall_bottom.color = SCREEN_COLOR_TERMINALGREEN;
    world.p_bodies.push_back(&wall_bottom);

    //Initialize Display
    tvtennis::vector screen_dimension;
    screen_dimension.x = SCREEN_WIDTH;
    screen_dimension.y = SCREEN_HEIGHT;
    tvtennis::screen* screen = new tvtennis::screen( screen_dimension, SCREEN_IS_FULL_SCREEN );
    if ( screen->initialize() == false ){
        std::cout << "Could not initialize display.  Exiting." << std::endl;;
        return RETURN_ERROR;
    }

    //Initialize Clock
    std::chrono::steady_clock clock;
    float delta_time = UTILITY_ZERO;
    std::chrono::_V2::steady_clock::time_point last_tick = clock.now();
    std::chrono::_V2::steady_clock::time_point this_tick;

    //Initialize Input
    tvtennis::controller controller;
    controller.map_control(tvtennis::input::key_escape, tvtennis::control::quit);
    controller.map_control(tvtennis::input::key_w, tvtennis::control::p1_up);
    controller.map_control(tvtennis::input::key_s, tvtennis::control::p1_down);


    //Enter Game Loop
    bool quit_bit = false;
    while ( quit_bit == false ){

        this_tick = clock.now();
        std::chrono::duration<float> time_since_last_tick = this_tick - last_tick;
        delta_time += time_since_last_tick.count();
        last_tick = this_tick;

        std::vector<tvtennis::control> inputs = controller.read_inputs();
        for ( int index = 0 ; index < inputs.size() ; index++ ){
            if ( inputs[index] == tvtennis::control::quit ){
                quit_bit = true;
            }
        }

        while ( delta_time >= ( SCREEN_REFRESH_TICK ) ){

            world.tick( SCREEN_REFRESH_TICK );

            if ( world.detect_collision(&ball, &racket_left) ){
                ball.velocity.x *= UTILITY_FACTOR_INVERT;
                ball.position.x = racket_left.position.x + racket_left.dimension.x;
            }
            if ( world.detect_collision(&ball, &racket_right) ){
                ball.velocity.x *= UTILITY_FACTOR_INVERT;
                ball.position.x = racket_right.position.x - ball.dimension.x;
            }
            if ( world.detect_collision(&ball, &wall_left) ){
                ball.velocity.x *= UTILITY_FACTOR_INVERT;
                ball.position.x = wall_left.dimension.x;
            }
            if ( world.detect_collision(&ball, &wall_right) ){
                ball.velocity.x *= UTILITY_FACTOR_INVERT;
                ball.position.x = wall_right.position.x - ball.dimension.x;
            }
            if ( world.detect_collision(&ball, &wall_top) ){
                ball.velocity.y *= UTILITY_FACTOR_INVERT;
                ball.position.y = wall_top.dimension.y;
            }
            if ( world.detect_collision(&ball, &wall_bottom) ){
                ball.velocity.y *= UTILITY_FACTOR_INVERT;
                ball.position.y = wall_bottom.position.y - ball.dimension.y;
            }

            delta_time -= SCREEN_REFRESH_TICK;
        }

        //Render World
        screen->render( SCREEN_COLOR_BLACK, world );
    }
    
    delete screen;
    return RETURN_OK;
}


