#include "ShootingRobot.h"
#include "../../util/Battlefield.h"
#include <stdexcept>

ShootingRobot::ShootingRobot(std::string name, int xPos, int yPos,
                             std::string symbol)
    : Robot(name, xPos, yPos, symbol)
{
}

void ShootingRobot::fire(int dx, int dy)
{
    int newX = xPos + dx;
    int newY = yPos + dy;

    if (dx == 0 && dy == 0)
    {
        throw std::invalid_argument(name + " attempted suicide");
    }
    else if (newX < 0 || newX >= battlefield->getXDim() || newY < 0 ||
             newY >= battlefield->getYDim())
    {
        throw std::out_of_range(
            "Target coordinates are out of battlefield bounds");
    }

    std::shared_ptr<Cell> targetCell = battlefield->getCell(newX, newY);
    if (targetCell->isOccupied())
    {
        battlefield->killRobot(shared_from_this(), targetCell);
    }

    battlefield->logEvent(name + " (" + symbol + ") fired at (" +
                          std::to_string(newX) + ", " + std::to_string(newY) +
                          ")");
}
