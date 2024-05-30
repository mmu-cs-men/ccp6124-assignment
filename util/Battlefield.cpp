#include "Battlefield.h"
#include "../robots/base/Robot.h"
#include "Helper.h"
#include <iostream>
#include <stdexcept>

Battlefield::Battlefield(int xDim, int yDim, int maxSteps)
    : xDim(xDim), yDim(yDim), maxSteps(maxSteps)
{
    for (int i = 0; i < xDim; i++)
    {
        DynamicArray<std::shared_ptr<Cell>> row;
        for (int j = 0; j < yDim; j++)
        {
            row.append(std::make_shared<Cell>(i, j));
        }
        battlefieldMatrix.append(row);
    }
}

void Battlefield::killRobot(std::shared_ptr<Cell> cell)
{
    // This should never happen
    if (!cell->isOccupied())
    {
        throw std::runtime_error(
            "Attempted to kill a robot in an unoccupied cell");
    }

    std::shared_ptr<Robot> robot = cell->getRobot();
    cell->removeRobot();

    respawnQueueStr.append(robot->getSymbol());

    robots.remove(robot);

    respawnQueue.enqueue(robot);

    logEvent(robot->getName() + " (" + robot->getSymbol() + ") was killed!");
}

void Battlefield::addRobot(std::shared_ptr<Robot> robot)
{
    if (!currentRobot)
    {
        currentRobot = robot;
    }

    robots.append(robot);
    battlefieldMatrix[robot->getXPos()][robot->getYPos()]->placeRobot(robot);
}

void Battlefield::nextRobot()
{
    if (robots.isEmpty())
    {
        throw std::runtime_error(
            "nextRobot() called when no robots have been added");
    }

    currentRobot = robots.next(currentRobot);
}

int Battlefield::getParticipatingRobots() const
{
    return robots.size() + respawnQueue.size();
}

void Battlefield::displayBattlefield()
{
    std::string border(xDim + 2, '*');
    std::cout << border << std::endl;
    for (int i = 0; i < xDim; i++)
    {
        std::cout << "*";
        for (int j = 0; j < yDim; j++)
        {
            std::cout << battlefieldMatrix[i][j]->getSymbol();
        }
        std::cout << "*" << std::endl;
    }
    std::cout << border << std::endl << std::endl;

    std::cout << "Steps: " << currentStep << "/" << maxSteps << std::endl;
    std::cout << "Respawn Queue: ";
    for (const std::string &robotSymbol : respawnQueueStr)
    {
        std::cout << robotSymbol;
    }
    std::cout << std::endl << std::endl;

    std::cout << "Event Log: " << std::endl;
    while (!eventQueue.isEmpty())
    {
        std::cout << eventQueue.dequeue() << std::endl;
    }
    std::cout << std::endl;
}

void Battlefield::respawnRobot()
{
    if (respawnQueue.isEmpty())
    {
        return;
    }

    auto robot = respawnQueue.dequeue();
    respawnQueueStr.remove(0);

    int randomX, randomY;
    do
    {
        randomX = Helper::generateRandomNumber(0, (xDim - 1));
        randomY = Helper::generateRandomNumber(0, (yDim - 1));
    } while (battlefieldMatrix[randomX][randomY]->isOccupied());

    robot->setXPos(randomX);
    robot->setYPos(randomY);
    battlefieldMatrix[randomX][randomY]->placeRobot(robot);

    robots.append(robot);
    eventQueue.enqueue(robot->getName() + " respawned");
}

void Battlefield::runSimulation(bool asap)
{
    while (currentStep <= maxSteps && getParticipatingRobots() > 1)
    {
        respawnRobot();

        currentRobot->executeActionPlan();

        displayBattlefield();

        if (!asap)
        {
            std::cout << "Press Enter to continue to next turn...";
            std::cin.get();
        }

        nextRobot();
        currentStep++;
    }
}

std::shared_ptr<Cell> Battlefield::getCell(int x, int y) const
{
    return battlefieldMatrix[x][y];
}

void Battlefield::logEvent(const std::string event)
{
    eventQueue.enqueue(event);
}

int Battlefield::getXDim() const
{
    return xDim;
}

int Battlefield::getYDim() const
{
    return yDim;
}
