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

#include "RoboTank.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"
#include "UltimateRobot.h"

RoboTank::RoboTank(std::string name, int xPos, int yPos, std::string symbol,
                   std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void RoboTank::executeActionPlan()
{
    int randomX;
    int randomY;

    do
    {
        randomX = Helper::generateRandomNumber(0, battlefield->getXDim() - 1);
        randomY = Helper::generateRandomNumber(0, battlefield->getYDim() - 1);
    } while (randomX == xPos && randomY == yPos);

    randomX = randomX - xPos;
    randomY = randomY - yPos;

    fire(randomX, randomY);
}

std::shared_ptr<Robot> RoboTank::upgrade()
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