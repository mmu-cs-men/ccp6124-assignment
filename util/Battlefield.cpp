/**********|**********|**********|
Program: Battlefield.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "Battlefield.h"
#include "../robots/base/Robot.h"
#include "Helper.h"
#include <iostream>
#include <stdexcept>

Battlefield::Battlefield(int xDim, int yDim, int maxSteps)
    : xDim(xDim), yDim(yDim), maxSteps(maxSteps), currentStep(1)
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

void Battlefield::killRobot(std::shared_ptr<Robot> killer,
                            std::shared_ptr<Cell> cell)
{
    // This should never happen
    if (!cell->isOccupied())
    {
        throw std::runtime_error(
            "Attempted to kill a robot in an unoccupied cell");
    }

    std::shared_ptr<Robot> robot = cell->getRobot();
    cell->removeRobot();
    robots.remove(robot);

    killer->incrementKillCount();
    std::shared_ptr<Robot> upgradedRobot = killer->upgrade();

    if (upgradedRobot)
    {
        getCell(killer->getXPos(), killer->getYPos())->removeRobot();
        upgradedRobot->setXPos(killer->getXPos());
        upgradedRobot->setYPos(killer->getYPos());
        getCell(killer->getXPos(), killer->getYPos())
            ->placeRobot(upgradedRobot);
        robots.replace(killer, upgradedRobot);

        if (killer == currentRobot)
        {
            currentRobot = upgradedRobot;
        }

        logEvent(killer->getName() + " (" + killer->getSymbol() +
                 ") has been upgraded to " + upgradedRobot->getType() + "!!!");
    }

    if (robot->getLives() > 0)
    {
        robot->decrementLives();
        respawnQueueStr.append(robot->getSymbol());
        respawnQueue.enqueue(robot);
    }

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

std::string Battlefield::getBattlefieldString()
{
    std::string output;
    std::string border;
    for (int i = 0; i < xDim * 2 + 3; i++)
    {
        border += (i % 2 == 0) ? "*" : " ";
    }
    output += border + "\n";
    for (int j = 0; j < yDim; j++)
    {
        output += "* ";
        for (int i = 0; i < xDim; i++)
        {
            output += battlefieldMatrix[i][j]->getSymbol() + " ";
        }
        output += "*\n";
    }
    output += border + "\n\n";

    output += "Steps: " + std::to_string(currentStep) + "/" +
              std::to_string(maxSteps) + "\n";
    output += "Respawn Queue: ";
    for (const std::string &robotSymbol : respawnQueueStr)
    {
        output += robotSymbol;
    }
    output += "\n\n";

    output += "Event Log: \n";
    while (!eventQueue.isEmpty())
    {
        output += eventQueue.dequeue() + "\n";
    }
    output += "\n";

    return output;
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
    eventQueue.enqueue(robot->getName() + " respawned at (" +
                       std::to_string(randomX) + ", " +
                       std::to_string(randomY) + ")");
}

void Battlefield::runSimulation(bool asap, bool clearTerminal)
{
    std::cin.ignore();

    while (currentStep <= maxSteps && getParticipatingRobots() > 1)
    {
        respawnRobot();

        currentRobot->executeActionPlan();

        if (!asap)
        {
            if (clearTerminal)
            {
                Helper::clearScreen();
            }
            std::string battlefieldString = getBattlefieldString();
            std::cout << battlefieldString;
            Helper::appendStrToLogFile(battlefieldString);
            std::cout << "Press Enter to continue to next turn..." << std::endl;
            std::cin.get();
        }
        else
        {
            Helper::appendStrToLogFile(getBattlefieldString());
        }

        nextRobot();
        currentStep++;
    }

    std::cout << std::endl << "Simulation has ended." << std::endl;

    if (getParticipatingRobots() == 1)
    {
        std::cout << "The winner is: " << robots.getHead()->getName() << " ("
                  << robots.getHead()->getType() << ")" << std::endl;
    }
    else
    {
        std::cout << "No winner. The simulation ended in a draw." << std::endl;
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
