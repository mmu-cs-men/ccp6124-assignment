/**********|**********|**********|
Program: SeeingRobot.h
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

#include "../../util/Cell.h"
#include "../../util/DynamicArray.h"
#include "Robot.h"
#include <array>

/**
 * @class SeeingRobot
 *
 * @brief An abstract class to be inherited by all robots that can look. This
 * class supplies the `look()` function.
 */
class SeeingRobot : virtual public Robot
{
    public:
        /**
         * @brief Constructs a SeeingRobot object.
         *
         * @param name The name of the robot.
         * @param xPos The initial x-coordinate of the robot.
         * @param yPos The initial y-coordinate of the robot.
         * @param symbol The symbol representing the robot.
         * @param type The type of the robot.
         */
        SeeingRobot(std::string name, int xPos, int yPos, std::string symbol,
                    std::string type);

        /**
         * @brief Looks around the robot's current position.
         *
         * This function returns a 3x3 grid of cells centered around the robot's
         * current position, offset by the specified dx and dy values. In other
         * words, this function takes in relative coordinates.
         *
         * Areas that are out of bounds and the cell that the robot is currently
         * in will be `nullptr`.
         *
         * @param dx The x-offset from the robot's current position.
         * @param dy The y-offset from the robot's current position.
         *
         * @return A 3x3 array of shared pointers to Cell objects representing
         * the cells around the robot's current position.
         */
        std::array<std::array<std::shared_ptr<Cell>, 3>, 3> look(int dx,
                                                                 int dy);
};
