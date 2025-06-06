/**********|**********|**********|
Program: Direction.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|**********/

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
