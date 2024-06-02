#include "TerminatorRoboCop.h"
#include "../util/Helper.h"

TerminatorRoboCop::TerminatorRoboCop(std::string name, int xPos, int yPos,
                                     std::string symbol)
    : ShootingRobot(name, xPos, yPos, symbol),
      SeeingRobot(name, xPos, yPos, symbol),
      SteppingRobot(name, xPos, yPos, symbol), Robot(name, xPos, yPos, symbol)
{
}

void TerminatorRoboCop::executeActionPlan()
{
    // Store original position
    int originalX = xPos;
    int originalY = yPos;

    // Look at current position
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
            }
        }
    }

    if (xPos == originalX || yPos == originalY)
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

    // Fire three times randomly (x+y <= 10)
    for (int i = 0; i < 3; i++)
    {
        int randomX = Helper::generateRandomNumber(0, 10);
        int randomY = Helper::generateRandomNumber(0, 10 - randomX);
        fire(randomX, randomY);
    }
}
