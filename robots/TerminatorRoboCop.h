#pragma once

#include "base/SeeingRobot.h"
#include "base/ShootingRobot.h"
#include "base/SteppingRobot.h"

class TerminatorRoboCop : public SeeingRobot,
                          public ShootingRobot,
                          public SteppingRobot
{
    public:
        TerminatorRoboCop(std::string name, int xPos, int yPos,
                          std::string symbol, std::string type);
        void executeActionPlan() override;
};
