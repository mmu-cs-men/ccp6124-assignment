/**********|**********|**********|
Program: RoboTank.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320@student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#include "RoboTank.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

RoboTank::RoboTank(std::string name, int xPos, int yPos,
                   std::string symbol, std::string type)
    : Robot(name, xPos, yPos, symbol, type), 
      ShootingRobot(name, xPos, yPos, symbol, type), 
      kills(0)
{
}

void RoboTank::executeActionPlan()
{
    // Fire at a random location in the battlefield
    int targetX, targetY;
    do
    {
        targetX = Helper::generateRandomNumber(0, battlefield->getXDim() - 1);
        targetY = Helper::generateRandomNumber(0, battlefield->getYDim() - 1);
    } while (targetX == xPos && targetY == yPos);

    if (battlefield->getCell(targetX, targetY)->isOccupied())
    {
        battlefield->killRobot(shared_from_this(), battlefield->getCell(targetX, targetY));
        kills++;
    }

    battlefield->logEvent(name + " (" + symbol + ") fired at (" +
                          std::to_string(targetX) + ", " + std::to_string(targetY) + ")");

    // Check if RoboTank should be upgraded to UltimateRobot
    if (kills >= 3)
    {
        // Upgrade to UltimateRobot logic here
        // This could involve creating an UltimateRobot instance and replacing this RoboTank instance
    }
}
