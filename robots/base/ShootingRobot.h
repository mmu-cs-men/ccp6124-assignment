/**********|**********|**********|
Program: ShootingRobot.h
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

#include "../../util/Direction.h"
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
         * @param type The type of the robot.
         */
        ShootingRobot(std::string name, int xPos, int yPos, std::string symbol,
                      std::string type);

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

        /**
         * @brief Fires at a target in the specified direction.
         *
         * This function takes in a direction and performs a firing action in
         * that direction relative to the robot's current position.
         *
         * @throws `std::out_of_range` - Will throw if the target is outside of
         * the battlefield.
         *
         * @param direction The direction in which to perform the firing
         * action.
         */
        void fire(Direction direction);
};
