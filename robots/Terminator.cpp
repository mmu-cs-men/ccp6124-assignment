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
        // type shouldn't matter here anymore since it won't be used
        return std::make_shared<TerminatorRoboCop>(name, xPos, yPos, symbol,
                                                   "TerminatorRoboCop");
    }
    return nullptr;
}
