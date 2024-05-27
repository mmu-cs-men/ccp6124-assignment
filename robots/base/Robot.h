#pragma once

#include "../../util/Battlefield.h"
#include <memory>
#include <string>

class Robot
{
    public:
        Robot(std::string name, int xPos, int yPos);
        void addBattlefield(std::shared_ptr<Battlefield> battlefield);
        virtual void executeActionPlan() = 0;
        virtual ~Robot() = default;

    private:
        std::string name;
        int xPos;
        int yPos;
        std::shared_ptr<Battlefield> battlefield;
};
