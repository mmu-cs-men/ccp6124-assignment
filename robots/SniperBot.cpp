/**********|**********|**********|
Program: SniperBot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
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
    } while (!randomCell || randomCell->isOccupied());

    move(randomCell->getX(), randomCell->getY());

    // Analyze look array for enemies and kill them
    for (auto &row : lookArr)
    {
        for (auto &cell : row)
        {
            if (cell && cell->isOccupied() &&
                cell->getRobot() != shared_from_this())
            {
                int dx = cell->getX() - xPos;
                int dy = cell->getY() - yPos;
                fire(dx, dy);
            }
        }
    }
}
