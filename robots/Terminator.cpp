#include "Terminator.h"

Terminator::Terminator(std::string name, int xPos, int yPos, std::string symbol)
    : SeeingRobot(name, xPos, yPos, symbol),
      SteppingRobot(name, xPos, yPos, symbol), Robot(name, xPos, yPos, symbol)
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
        for (auto &item : row)
        {
            if (!item)
            {
                continue;
            }
            else if (item->isOccupied())
            {
                stomp(item->getX(), item->getY());
                return;
            }
        }
    }

    Direction randomDirection =
        static_cast<Direction>(Helper::generateRandomNumber(1, 7));

    stomp(randomDirection);
}
