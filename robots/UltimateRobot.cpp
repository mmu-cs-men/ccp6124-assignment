/**********|**********|**********|
Program: UltimateRobot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#include "UltimateRobot.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

UltimateRobot::UltimateRobot(std::string name, int xPos, int yPos,
                             std::string symbol, std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      SeeingRobot(name, xPos, yPos, symbol, type),
      SteppingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void UltimateRobot::executeActionPlan()
{
    // Store original position
    int originalX = xPos;
    int originalY = yPos;

    // Look at current position
    auto lookArr = look(0, 0);

    // Determine which neighbor has robot. If no neighbor, move randomly
    // If neighbor, step on it
    bool stomped = false;
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
                stomped = true;
                break;
            }
        }
        if (stomped)
            break;
    }

    if (!stomped)
    {
        std::shared_ptr<Cell> randomCell;
        do
        {
            int randomX = Helper::generateRandomNumber(0, 2);
            int randomY = Helper::generateRandomNumber(0, 2);
            randomCell = lookArr[randomX][randomY];
        } while (!randomCell);

        stomp(randomCell->getX(), randomCell->getY());
    }

    // Fire three times randomly (no distance limit)
    for (int i = 0; i < 3; i++)
    {
        int randomX;
        int randomY;

        do
        {
            randomX =
                Helper::generateRandomNumber(0, battlefield->getXDim() - 1);
            randomY =
                Helper::generateRandomNumber(0, battlefield->getYDim() - 1);
        } while (randomX == xPos && randomY == yPos);

        randomX = randomX - xPos;
        randomY = randomY - yPos;

        fire(randomX, randomY);
    }
}
