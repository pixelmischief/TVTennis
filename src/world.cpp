#include <iostream>
#include <SDL2/SDL.h>
#include "world.hpp"

tvtennis::world::world(){
    p_bodies.clear();
    dimension = { 0.0, 0.0 };
}

void tvtennis::world::tick(const float delta_time){

    std::vector<collision> collisions;
    collisions.clear();

    for ( int index = 0 ; index < p_bodies.size() ; index++ ){
        body* p_body = p_bodies[index];
        p_body->position.x += p_body->velocity.x * delta_time;
        p_body->position.y += p_body->velocity.y * delta_time;
    }
}

bool tvtennis::world::detect_collision( const body* a, const body* b ){
    return ((
        a->position.x >= b->position.x &&
        a->position.x <= b->position.x + b->dimension.x &&
        a->position.y >= b->position.y &&
        a->position.y <= b->position.y + b->dimension.y
    ) || (
        a->position.x + a->dimension.x >= b->position.x &&
        a->position.x + a->dimension.x <= b->position.x + b->dimension.x &&
        a->position.y >= b->position.y &&
        a->position.y <= b->position.y + b->dimension.y
    ) || (
        a->position.x >= b->position.x &&
        a->position.x <= b->position.x + b->dimension.x &&
        a->position.y + a->dimension.y >= b->position.y &&
        a->position.y + a->dimension.y <= b->position.y + b->dimension.y
    ) || (
        a->position.x + a->dimension.x >= b->position.x &&
        a->position.x + a->dimension.x <= b->position.x + b->dimension.x &&
        a->position.y + a->dimension.y >= b->position.y &&
        a->position.y + a->dimension.y <= b->position.y + b->dimension.y
    ));
}