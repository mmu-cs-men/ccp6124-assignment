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

#include "SniperBot.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

SniperBot::SniperBot(std::string name, int xPos, int yPos, std::string symbol,
                     std::string type)
    : MovingRobot(name, xPos, yPos, symbol, type),
      ShootingRobot(name, xPos, yPos, symbol, type),
      SeeingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void SniperBot::executeActionPlan()
{
    // Look around
    auto lookArr = look(0, 0);

    // Move randomly
    // TODO: This will infinite loop if the robot is completely surrounded.
    // Seems unlikely tho...
    std::shared_ptr<Cell> randomCell;
    do
    {
        int randomX = Helper::generateRandomNumber(0, 2);
        int randomY = Helper::generateRandomNumber(0, 2);
        randomCell = lookArr[randomX][randomY];
    } while (randomCell->isOccupied());

    move(randomCell->getX(), randomCell->getY());

    // Analyze look array for enemies and kill them
    for (auto &row : lookArr)
    {
        for (auto &cell : row)
        {
            if (cell->isOccupied())
            {
                fire(cell->getX(), cell->getY());
            }
        }
    }
}
