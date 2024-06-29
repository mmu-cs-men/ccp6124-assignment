#pragma once

#include "base/ShootingRobot.h"

class Landmine : public ShootingRobot
{
    public:
        Landmine(std::string name, int xPos, int yPos, std::string symbol,
                 std::string type);
        void executeActionPlan() override;
};