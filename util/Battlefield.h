#pragma once

#include "../robots/base/Robot.h"
#include "CircularLinkedList.h"
#include <memory>

class Battlefield
{
    public:
        Battlefield(int xDim, int yDim, int maxSteps);
        void addRobot(std::shared_ptr<Robot> robot);
        void runSimulation(bool asap);

    private:
        void nextRobot();
        CircularLinkedList<std::shared_ptr<Robot>> robots;
        std::shared_ptr<Robot> currentRobot;
        int xDim;
        int yDim;
        int maxSteps;
        int currentStep;
};
