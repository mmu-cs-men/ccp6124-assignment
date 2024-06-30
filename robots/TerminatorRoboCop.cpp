/**********|**********|**********|
Program: TerminatorRoboCop.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "TerminatorRoboCop.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"
#include "UltimateRobot.h"

TerminatorRoboCop::TerminatorRoboCop(std::string name, int xPos, int yPos,
                                     std::string symbol, std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      SeeingRobot(name, xPos, yPos, symbol, type),
      SteppingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void TerminatorRoboCop::executeActionPlan()
{
    // Store original position
    int originalX = xPos;
    int originalY = yPos;

    // Look at current position
    auto lookArr = look(0, 0);

    // Determine which neighbor has robot. If no neighbor, move randomly
    // If neighbor, step on it
    bool stomped = false;
    for (auto &row : lookArr)
    {
        for (auto &cell : row)
        {
            if (!cell)
            {
                continue;
            }
            else if (cell->isOccupied())
            {
                stomp(cell->getX(), cell->getY());
                stomped = true;
                break;
            }
        }
        if (stomped)
            break;
    }

    if (!stomped)
    {
        std::shared_ptr<Cell> randomCell;
        do
        {
            int randomX = Helper::generateRandomNumber(0, 2);
            int randomY = Helper::generateRandomNumber(0, 2);
            randomCell = lookArr[randomX][randomY];
        } while (!randomCell);

        stomp(randomCell->getX(), randomCell->getY());
    }

    // Fire three times randomly (x+y <= 10)
    for (int i = 0; i < 3; i++)
    {
        int randomX, randomY;
        do
        {
            randomX = Helper::generateRandomNumber(
                -std::min(10, xPos),
                std::min(10, battlefield->getXDim() - xPos - 1));
            randomY = Helper::generateRandomNumber(
                -std::min(10 - std::abs(randomX), yPos),
                std::min(10 - std::abs(randomX),
                         battlefield->getYDim() - yPos - 1));
        } while (randomX == 0 && randomY == 0);
        fire(randomX, randomY);
    }
}

std::shared_ptr<Robot> TerminatorRoboCop::upgrade()
{
    if (killCount >= 3)
    {
        std::shared_ptr<UltimateRobot> upgradedRobot =
            std::make_shared<UltimateRobot>(name, xPos, yPos, symbol,
                                            "UltimateRobot");

        upgradedRobot->addBattlefield(battlefield);

        return upgradedRobot;
    }
    return nullptr;
}