#ifndef TVT_CONFIGURATION_H
#define TVT_CONFIGURATION_H

#include "utility.hpp"

namespace tvtennis {

    const int SCREEN_WIDTH = 1600;
    const int SCREEN_HEIGHT = 1200;
    const bool SCREEN_IS_FULL_SCREEN = false;
    const float SCREEN_FRAMES_PER_SECOND = 60.0f;

    const float WORLD_UNIT = 1.0f;
    const float WORLD_WIDTH = 80.0f;
    const float WORLD_HEIGHT = 60.0f;
    const float WORLD_SLOW_MOTION_FACTOR = FACTOR_TEN;

    const float FIXTURE_BALL_DIMENSIONS = WORLD_UNIT;
    const float FIXTURE_BALL_MIN_VELOCITY_X = WORLD_UNIT * FACTOR_TWENTY;
    const float FIXTURE_BALL_MAX_VELOCITY_X = FIXTURE_BALL_MIN_VELOCITY_X * FACTOR_FOUR;
    const float FIXTURE_RACKET_WIDTH = WORLD_UNIT;
    const float FIXTURE_RACKET_HEIGHT = FIXTURE_RACKET_WIDTH * FACTOR_FIVE;
    const float FIXTURE_RACKET_SPACING = FIXTURE_RACKET_WIDTH * FACTOR_FOUR;
    const float FIXTURE_WALL_THICKNESS = WORLD_UNIT;

}

#endif