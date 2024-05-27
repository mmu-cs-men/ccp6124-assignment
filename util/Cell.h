#pragma once

#include "../robots/base/Robot.h"
#include <memory>

class Cell
{
    public:
        Cell(int x, int y);

        bool isOccupied() const;
        void placeRobot(std::shared_ptr<Robot> newRobot);
        void removeRobot();
        std::shared_ptr<Robot> getRobot() const;
        std::string getSymbol() const;

    private:
        std::shared_ptr<Robot> robot;
        int x;
        int y;
};
