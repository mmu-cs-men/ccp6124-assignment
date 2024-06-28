/**********|**********|**********|
Program: UltimateRobot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: [Your Name]
ID: [Your ID]
Lecture Section: [Your Lecture Section]
Tutorial Section: [Your Tutorial Section]
Email: [Your Email]
Phone: [Your Phone]
**********|**********|**********/

#include "UltimateRobot.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

UltimateRobot::UltimateRobot(std::string name, int xPos, int yPos,
                             std::string symbol, std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      SeeingRobot(name, xPos, yPos, symbol, type),
      SteppingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type),
      kills(0)
{
}

void UltimateRobot::executeActionPlan()
{
    // Step on any robot in the immediate vicinity
    auto lookArr = look(0, 0);
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
                kills++;
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

    // Fire three times at random locations in the battlefield
    for (int i = 0; i < 3; i++)
    {
        int randomX, randomY;
        do
        {
            randomX = Helper::generateRandomNumber(0, battlefield->getXDim() - 1);
            randomY = Helper::generateRandomNumber(0, battlefield->getYDim() - 1);
        } while (randomX == xPos && randomY == yPos);
        fire(randomX - xPos, randomY - yPos);
    }

    // Check if UltimateRobot should be upgraded further based on some logic
    // This is a placeholder for any further upgrade logic
}

