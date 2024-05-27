#pragma once

#include "Robot.h"

class ShootingRobot : virtual public Robot
{
    public:
        ShootingRobot(std::string name, int xPos, int yPos, std::string symbol);
        void fire(int dx, int dy);
};
