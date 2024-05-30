#pragma once

#include "Cell.h"
#include "CircularLinkedList.h"
#include "DynamicArray.h"
#include "Queue.h"
#include <memory>
#include <string>

// Needed to avoid circular dependency
class Robot;

class Battlefield
{
    public:
        Battlefield(int xDim, int yDim, int maxSteps);
        void addRobot(std::shared_ptr<Robot> robot);
        void runSimulation(bool asap);
        std::shared_ptr<Cell> getCell(int x, int y) const;
        void logEvent(const std::string event);
        int getXDim() const;
        int getYDim() const;
        void killRobot(std::shared_ptr<Cell> cell);

    private:
        void nextRobot();
        void displayBattlefield();
        int getParticipatingRobots() const;
        void respawnRobot();
        Queue<std::shared_ptr<Robot>> respawnQueue;
        Queue<std::string> eventQueue;
        CircularLinkedList<std::shared_ptr<Robot>> robots;
        DynamicArray<DynamicArray<std::shared_ptr<Cell>>> battlefieldMatrix;
        std::shared_ptr<Robot> currentRobot;
        DynamicArray<std::string> respawnQueueStr;
        int xDim;
        int yDim;
        int maxSteps;
        int currentStep = 1;
};
