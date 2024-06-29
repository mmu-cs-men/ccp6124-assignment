/**********|**********|**********|
Program: Terminator.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "Terminator.h"
#include "TerminatorRoboCop.h"

Terminator::Terminator(std::string name, int xPos, int yPos, std::string symbol,
                       std::string type)
    : SeeingRobot(name, xPos, yPos, symbol, type),
      SteppingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void Terminator::executeActionPlan()
{
    // Performs a look action around it
    auto lookArr = look(0, 0);

    // Determine which neighbor has robot. If no neighbor, move randomly
    // If neighbor, step on it
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
                return;
            }
        }
    }

    std::shared_ptr<Cell> randomCell;
    do
    {
        int randomX = Helper::generateRandomNumber(0, 2);
        int randomY = Helper::generateRandomNumber(0, 2);
        randomCell = lookArr[randomX][randomY];
    } while (!randomCell);

    stomp(randomCell->getX(), randomCell->getY());
}

std::shared_ptr<Robot> Terminator::upgrade()
{
    if (killCount >= 3)
    {
        std::shared_ptr<TerminatorRoboCop> upgradedRobot =
            std::make_shared<TerminatorRoboCop>(name, xPos, yPos, symbol,
                                                "TerminatorRoboCop");

        upgradedRobot->addBattlefield(battlefield);

        return upgradedRobot;
    }
    return nullptr;
}
