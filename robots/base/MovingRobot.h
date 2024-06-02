#pragma once

#include "../../util/Direction.h"
#include "Robot.h"
#include <string>

/**
 * @class MovingRobot
 *
 * @brief An abstract class to be inherited by all robots that can move. This
 * class supplies the `move()` function.
 *
 * @note Do not inherit this class if your robot can step. In that case, you
 * must only inherit from SteppingRobot, as it provides move funtionality as
 * well.
 */
class MovingRobot : virtual public Robot
{
    public:
        /**
         * @brief Constructs a MovingRobot object.
         *
         * @param name The name of the robot.
         * @param xPos The initial x-coordinate of the robot.
         * @param yPos The initial y-coordinate of the robot.
         * @param symbol The symbol representing the robot.
         * @param type The type of the robot.
         */
        MovingRobot(std::string name, int xPos, int yPos, std::string symbol,
                    std::string type);

        /**
         * @brief Moves the robot to a specified position.
         *
         * If you supply invalid coordinates (moving out of battlefield, moving
         * to occupied position), the robot will not move. Instead, your illegal
         * action will be displayed in the event log.
         *
         * @param x The new absolute x-coordinate of the robot.
         * @param y The new absolute y-coordinate of the robot.
         *
         * @throws std::invalid_argument if x and y are beyond a 3x3 area around
         * the robot.
         *
         * @note Unlike some other functions in this assignment, this function
         * takes in absolute coordinates. They are not relative to the robot.
         */
        void move(int x, int y);

        /**
         * @brief Moves the robot in a specified direction.
         *
         * If you attempt to move the robot out of the battlefield or to an
         * occupied position, the robot will not move. Instead, your illegal
         * action will be displayed in the event log.
         *
         * @param direction The direction in which to move the robot.
         */
        void move(Direction direction);
};
