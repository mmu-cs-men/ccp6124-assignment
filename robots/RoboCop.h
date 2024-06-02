#pragma once

#include "base/MovingRobot.h"
#include "base/SeeingRobot.h"
#include "base/ShootingRobot.h"

class RoboCop : public MovingRobot, public SeeingRobot, public ShootingRobot
{
    public:
        RoboCop(std::string name, int xPos, int yPos, std::string symbol);
        void executeActionPlan() override;
        std::shared_ptr<Robot> upgrade() override;
};
