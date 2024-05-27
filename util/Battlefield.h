#pragma once

#include "CircularLinkedList.h"
#include <memory>

// Needed to avoid circular dependency
class Robot;

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
