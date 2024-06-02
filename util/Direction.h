#pragma once

/**
 * @enum Direction
 * @brief Represents relative directions in a 3x3 grid. Useful when you don't
 * care about specific coordinates.
 */
enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_RIGHT,
    DOWN_RIGHT,
    DOWN_LEFT,
    UP_LEFT
};
