#include "game.hpp"

tvtennis::game::game(){


    color terminal_green;
    terminal_green.r = COLOR_TERMINALGREEN_R;
    terminal_green.g = COLOR_TERMINALGREEN_G;
    terminal_green.b = COLOR_TERMINALGREEN_B;
    terminal_green.a = COLOR_TERMINALGREEN_A;

    world.dimension = { WORLD_WIDTH, WORLD_HEIGHT };

    //Ball
    ball.dimension = { FIXTURE_BALL_DIMENSIONS, FIXTURE_BALL_DIMENSIONS };
    ball.position = { WORLD_WIDTH * FACTOR_HALF, WORLD_HEIGHT * FACTOR_HALF };
    ball.velocity = { FIXTURE_BALL_MIN_VELOCITY_X * FACTOR_INVERT, ZERO };
    ball.color = terminal_green;
    ball.is_fixture = false;
    world.p_bodies.push_back(&ball);

    //Rackets
    racket_left.dimension = { FIXTURE_RACKET_WIDTH, FIXTURE_RACKET_HEIGHT };
    racket_left.position = { FIXTURE_RACKET_SPACING, ( WORLD_HEIGHT * FACTOR_HALF ) - ( FIXTURE_RACKET_HEIGHT * FACTOR_HALF ) };
    racket_left.velocity = { ZERO, ZERO };
    racket_left.color = terminal_green;
    racket_left.is_fixture = true;
    world.p_bodies.push_back(&racket_left);

    racket_right.dimension = { FIXTURE_RACKET_WIDTH, FIXTURE_RACKET_HEIGHT };
    racket_right.position = { WORLD_WIDTH - FIXTURE_RACKET_SPACING - FIXTURE_RACKET_WIDTH, ( WORLD_HEIGHT * FACTOR_HALF ) - ( FIXTURE_RACKET_HEIGHT * FACTOR_HALF ) };
    racket_right.velocity = { ZERO, ZERO };
    racket_right.color = terminal_green;
    racket_right.is_fixture = true;
    world.p_bodies.push_back(&racket_right);

    //Walls
    wall_left.dimension = { FIXTURE_WALL_THICKNESS, WORLD_HEIGHT };
    wall_left.position = { ZERO, ZERO };
    wall_left.velocity = { ZERO, ZERO };
    wall_left.color = terminal_green;
    wall_left.is_fixture = true;
    world.p_bodies.push_back(&wall_left);

    wall_right.dimension = { FIXTURE_WALL_THICKNESS, WORLD_HEIGHT };
    wall_right.position = { ( WORLD_WIDTH - WORLD_UNIT ), ZERO };
    wall_right.velocity = { ZERO, ZERO };
    wall_right.color = terminal_green;
    wall_right.is_fixture = true;
    world.p_bodies.push_back(&wall_right);

    wall_top.dimension = { WORLD_WIDTH, FIXTURE_WALL_THICKNESS };
    wall_top.position = { ZERO, ZERO };
    wall_top.velocity = { ZERO, ZERO };
    wall_top.color = terminal_green;
    wall_top.is_fixture = true;
    world.p_bodies.push_back(&wall_top);

    wall_bottom.dimension = { WORLD_WIDTH, FIXTURE_WALL_THICKNESS };
    wall_bottom.position = { ZERO, WORLD_HEIGHT - WORLD_UNIT };
    wall_bottom.velocity = { ZERO, ZERO };
    wall_bottom.color = terminal_green;
    wall_bottom.is_fixture = true;
    world.p_bodies.push_back(&wall_bottom);

    state = state::initialized;
}

tvtennis::game::~game(){;}

void tvtennis::game::process(const float time, const std::vector<input> inputs){

    world.tick( time );

    if ( world.detect_collision(&ball, &racket_left) ){
        ball.velocity.x *= FACTOR_INVERT;
        ball.position.x = racket_left.position.x + racket_left.dimension.x;
    }
    if ( world.detect_collision(&ball, &racket_right) ){
        ball.velocity.x *= FACTOR_INVERT;
        ball.position.x = racket_right.position.x - ball.dimension.x;
    }
    if ( world.detect_collision(&ball, &wall_left) ){
        ball.velocity.x *= FACTOR_INVERT;
        ball.position.x = wall_left.dimension.x;
    }
    if ( world.detect_collision(&ball, &wall_right) ){
        ball.velocity.x *= FACTOR_INVERT;
        ball.position.x = wall_right.position.x - ball.dimension.x;
    }
    if ( world.detect_collision(&ball, &wall_top) ){
        ball.velocity.y *= FACTOR_INVERT;
        ball.position.y = wall_top.dimension.y;
    }
    if ( world.detect_collision(&ball, &wall_bottom) ){
        ball.velocity.y *= FACTOR_INVERT;
        ball.position.y = wall_bottom.position.y - ball.dimension.y;
    }

}

void tvtennis::game::display(const screen* p_screen){

}

