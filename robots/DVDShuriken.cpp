/**********|**********|**********|
Program: DVDShuriken.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102008@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#include "DVDShuriken.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

DVDShuriken::DVDShuriken(std::string name, int xPos, int yPos,
                         std::string symbol, std::string type)
    : SteppingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void DVDShuriken::executeActionPlan()
{
    if (!lastDx || !lastDy)
    {
        int randomDx;
        int randomDy;
        do
        {
            randomDx = Helper::generateRandomNumber(-1, 1);
            randomDy = Helper::generateRandomNumber(-1, 1);
        } while (
            randomDx == 0 && randomDy == 0 ||
            !battlefield->isInBattlefield(xPos + randomDx, yPos + randomDy));

        lastDx = std::make_unique<int>(randomDx);
        lastDy = std::make_unique<int>(randomDy);
    }

    int dx = *lastDx;
    int dy = *lastDy;
    int targetX = xPos + dx;
    int targetY = yPos + dy;

    if (!battlefield->isInBattlefield(targetX, targetY))
    {
        lastDx = nullptr;
        lastDy = nullptr;
        executeActionPlan();
        return;
    }

    stomp(xPos + dx, yPos + dy);
}
