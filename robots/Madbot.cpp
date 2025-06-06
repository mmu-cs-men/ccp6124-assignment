/**********|**********|**********|
Program: Madbot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|**********/

#include "Madbot.h"
#include "../util/Helper.h"
#include "RoboTank.h"
#include <stdexcept>

Madbot::Madbot(std::string name, int xPos, int yPos, std::string symbol,
               std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void Madbot::executeActionPlan()
{
    Direction randomDirection =
        static_cast<Direction>(Helper::generateRandomNumber(0, 7));
    try
    {
        fire(randomDirection);
    }
    catch (const std::out_of_range &e)
    {
        executeActionPlan();
        return;
    }
}

std::shared_ptr<Robot> Madbot::upgrade()
{
    if (killCount >= 3)
    {
        std::shared_ptr<RoboTank> upgradedRobot =
            std::make_shared<RoboTank>(name, xPos, yPos, symbol, "RoboTank");

        upgradedRobot->addBattlefield(battlefield);
        upgradedRobot->setLives(lives);

        return upgradedRobot;
    }
    return nullptr;
}