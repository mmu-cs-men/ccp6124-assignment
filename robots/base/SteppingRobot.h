#pragma once

#include "../../util/Direction.h"
#include "Robot.h"

class SteppingRobot : virtual public Robot
{
    public:
        SteppingRobot(std::string name, int xPos, int yPos, std::string symbol);
        void stomp(int x, int y);
        void stomp(Direction direction);
};
