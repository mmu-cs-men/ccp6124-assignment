#pragma once

#include "base/SteppingRobot.h"
#include <memory>

class DVDShuriken : public SteppingRobot
{
    public:
        DVDShuriken(std::string name, int xPos, int yPos, std::string symbol,
                    std::string type);
        void executeActionPlan() override;

    private:
        std::unique_ptr<int> lastDx;
        std::unique_ptr<int> lastDy;
};
