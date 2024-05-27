#pragma once

#include "../../util/Battlefield.h"
#include <memory>
#include <string>

class Robot : public std::enable_shared_from_this<Robot>
{
    public:
        Robot(std::string name, int xPos, int yPos, std::string symbol);
        void addBattlefield(std::shared_ptr<Battlefield> battlefield);
        virtual void executeActionPlan() = 0;
        virtual ~Robot() = default;
        std::string getName() const;
        int getXPos() const;
        int getYPos() const;
        void setXPos(int xPos);
        void setYPos(int yPos);
        std::string getSymbol() const;

    protected:
        std::string name;
        int xPos;
        int yPos;
        std::string symbol;
        std::shared_ptr<Battlefield> battlefield;
};
