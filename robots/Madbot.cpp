/**********|**********|**********|
Program: MadBot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|***********/

#include "Madbot.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

Madbot::Madbot(const std::string &name, int x, int y, const std::string &symbol,
               const std::string &type)
    : Robot(name, x, y, symbol, type), ShootingRobot(name, x, y, symbol, type)
{
}

void Madbot::executeActionPlan()
{
    int dx, dy;

    do
    {
        dx = Helper::generateRandomNumber(-1, 1);
        dy = Helper::generateRandomNumber(-1, 1);
    } while ((dx == 0 && dy == 0) || !isValidTarget(dx, dy));

    fire(dx, dy);
}

bool Madbot::isValidTarget(int dx, int dy)
{
    int targetX = getXPos() + dx;
    int targetY = getYPos() + dy;

    return (targetX >= 0 && targetX < battlefield->getXDim() && targetY >= 0 &&
            targetY < battlefield->getYDim());
}
