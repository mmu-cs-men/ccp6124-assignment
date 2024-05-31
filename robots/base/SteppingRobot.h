#pragma once

#include "../../util/Direction.h"
#include "Robot.h"

/**
 * @class SteppingRobot
 *
 * @brief An abstract class to be inherited by all robots that can step. This
 * class supplies the `stomp()` function.
 *
 * @note If your robot can step, then it doesn't have to inherit from
 * MovingRobot because `stomp()` acts as `move()` if there isn't a robot in the
 * position it's moving to.
 */
class SteppingRobot : virtual public Robot
{
    public:
        /**
         * @brief Constructs a SteppingRobot object.
         *
         * @param name The name of the robot.
         * @param xPos The initial x-coordinate of the robot.
         * @param yPos The initial y-coordinate of the robot.
         * @param symbol The symbol representing the robot.
         * @param type The type of the robot.
         */
        SteppingRobot(std::string name, int xPos, int yPos, std::string symbol,std::string type);

        /**
         * @brief Performs a stomping action at the specified coordinates.
         *
         * This function takes in absolute coordinates and performs a
         * stomping action at that position, which will kill a robot if one is
         * in that position. Else, it will simply move the robot similar to
         * move().
         *
         * If you supply invalid coordinates (moving further than 3x3, moving
         * out of battlefield), the robot will not move. Instead, your illegal
         * action will be displayed in the event log.
         *
         * @param x The x-coordinate where the stomping action will be
         * performed.
         * @param y The y-coordinate where the stomping action will be
         * performed.
         *
         * @note Unlike some other functions in this assignment, this function
         * takes in absolute coordinates. They are not relative to the robot.
         */
        void stomp(int x, int y);

        /**
         * @brief Performs a stomping action in the specified direction.
         *
         * This function takes in a direction and performs a stomping action in
         * that direction relative to the robot's current position.
         *
         * If you attempt to stomp the robot out of the battlefield, the robot
         * will not move. Instead, your illegal action will be displayed in the
         * event log.
         *
         * @param direction The direction in which to perform the stomping
         * action.
         */
        void stomp(Direction direction);
};
