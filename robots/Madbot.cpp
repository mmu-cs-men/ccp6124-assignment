/**********|**********|**********|
Program: BlueThunder.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai A/L Ramesh Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 12211020080@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#include "Madbot.h"
#include "../util/Helper.h"
#include "RoboTank.h"

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
    fire(randomDirection);
}

std::shared_ptr<Robot> Madbot::upgrade()
{
    if (killCount >= 3)
    {
        std::shared_ptr<RoboTank> upgradedRobot =
            std::make_shared<RoboTank>(name, xPos, yPos, symbol, "RoboTank");

        upgradedRobot->addBattlefield(battlefield);

        return upgradedRobot;
    }
    return nullptr;
}