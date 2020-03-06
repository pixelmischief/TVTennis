#include <iostream>
#include <math.h>
#include "screen.hpp"


tvtennis::screen::screen( const tvtennis::vector dimension, const bool is_full_screen ){
    _dimension = dimension;
    _is_full_screen = is_full_screen;
}

tvtennis::screen::~screen(){
    SDL_DestroyRenderer(_render_target);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool tvtennis::screen::initialize(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize display: %s\n", SDL_GetError());
        return false;
    }

    _window = SDL_CreateWindow(
        "TV Tennis",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        _dimension.x, _dimension.y,
        SDL_WINDOW_SHOWN
    );
    if (_window == nullptr) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return false;
    }

    if ( _is_full_screen == true ){
        if ( SDL_SetWindowFullscreen( _window, SDL_WINDOW_FULLSCREEN) < 0 ){
            fprintf(stderr, "Could not set window to full screen: %s\n", SDL_GetError());
            return false;
        }
    }

    _render_target = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
    );
    if (_render_target == nullptr) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void tvtennis::screen::render(const tvtennis::color clear_color, const tvtennis::world world){

    SDL_SetRenderDrawColor(
        _render_target,
        clear_color.r,
        clear_color.g,
        clear_color.b,
        clear_color.a
    );

    SDL_RenderClear(_render_target);

    float scale_x = _dimension.x / world.dimension.x;
    float scale_y = _dimension.y / world.dimension.y;

    for ( int index = 0 ; index < world.p_bodies.size() ; index++ ){

        body* p_body = world.p_bodies[index];

        SDL_Rect rectangle;
        rectangle.x = p_body->position.x * scale_x;
        rectangle.y = p_body->position.y * scale_y;
        rectangle.w = p_body->dimension.x * scale_x;
        rectangle.h = p_body->dimension.y * scale_y;

        SDL_SetRenderDrawColor(
            _render_target,
            p_body->color.r,
            p_body->color.g,
            p_body->color.b,
            p_body->color.a
        );

        SDL_RenderFillRect(_render_target, &rectangle);

    }

    SDL_RenderPresent(_render_target);
}