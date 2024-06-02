/**********|**********|**********|
Program: RoboCop.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "RoboCop.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"
#include "TerminatorRoboCop.h"

RoboCop::RoboCop(std::string name, int xPos, int yPos, std::string symbol)
    : MovingRobot(name, xPos, yPos, symbol),
      ShootingRobot(name, xPos, yPos, symbol),
      SeeingRobot(name, xPos, yPos, symbol), Robot(name, xPos, yPos, symbol)
{
}

void RoboCop::executeActionPlan()
{
    // Look at current position
    auto lookArr = look(0, 0);

    // Move randomly to valid position
    std::shared_ptr<Cell> randomCell;
    do
    {
        int randomX = Helper::generateRandomNumber(0, 2);
        int randomY = Helper::generateRandomNumber(0, 2);
        randomCell = lookArr[randomX][randomY];
    } while (!randomCell || randomCell->isOccupied());

    move(randomCell->getX(), randomCell->getY());

    // Fire three times randomly (x+y <= 10)
    for (int i = 0; i < 3; i++)
    {
        int randomX = Helper::generateRandomNumber(0, 10);
        int randomY = Helper::generateRandomNumber(0, 10 - randomX);
        fire(randomX, randomY);
    }
}

std::shared_ptr<Robot> RoboCop::upgrade()
{
    if (killCount >= 3)
    {
        return std::make_shared<TerminatorRoboCop>(name, xPos, yPos, symbol);
    }
    return nullptr;
}
