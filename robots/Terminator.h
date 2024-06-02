#pragma once

#include "../util/Direction.h"
#include "../util/Helper.h"
#include "base/SeeingRobot.h"
#include "base/SteppingRobot.h"

class Terminator : public SeeingRobot, public SteppingRobot
{
    public:
        Terminator(std::string name, int xPos, int yPos, std::string symbol,
                   std::string type);
        void executeActionPlan() override;
        std::shared_ptr<Robot> upgrade() override;
};
