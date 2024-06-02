/**********|**********|**********|
Program: ShootingRobot.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#pragma once

#include "Robot.h"

/**
 * @class ShootingRobot
 *
 * @brief An abstract class to be inherited by all robots that can shoot. This
 * class supplies the `fire()` function.
 */
class ShootingRobot : virtual public Robot
{
    public:
        /**
         * @brief Constructs a ShootingRobot object.
         *
         * @param name The name of the robot.
         * @param xPos The initial x-coordinate of the robot.
         * @param yPos The initial y-coordinate of the robot.
         * @param symbol The symbol representing the robot.
         */
        ShootingRobot(std::string name, int xPos, int yPos, std::string symbol);

        /**
         * @brief Fires at a target relative to the robot's current position.
         *
         * This function takes in relative coordinates (dx, dy) and performs a
         * shooting action in that direction. There are no distance restrictions
         * in this function.
         *
         * @throws `std::invalid_argument` - Will throw if dx and dy are 0
         * (suicide).
         * @throws `std::out_of_range` - Will throw if dx and dy are outside
         * of the battlefield.
         *
         * @param dx The x-offset from the robot's current position.
         * @param dy The y-offset from the robot's current position.
         */
        void fire(int dx, int dy);
};
