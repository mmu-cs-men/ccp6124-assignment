#include "SteppingRobot.h"
#include "../../util/Battlefield.h"

SteppingRobot::SteppingRobot(std::string name, int xPos, int yPos,
                             std::string symbol)
    : Robot(name, xPos, yPos, symbol)
{
}

void SteppingRobot::stomp(int x, int y)
{
    if (abs(x - xPos) > 1 || abs(y - yPos) > 1)
    {
        throw std::invalid_argument(name + " (" + symbol +
                                    ") attempted an illegal stomp");
    }
    else if (x < 0 || x >= battlefield->getXDim() || y < 0 ||
             y >= battlefield->getYDim())
    {
        battlefield->logEvent(name + " (" + symbol +
                              ") attempted to stomp out of battlefield");
        return;
    }

    std::shared_ptr<Cell> targetCell = battlefield->getCell(x, y);
    if (targetCell->isOccupied())
    {
        battlefield->logEvent(name + " (" + symbol + ") stomped on (" +
                              std::to_string(x) + ", " + std::to_string(y) +
                              ")");
        battlefield->killRobot(shared_from_this(), targetCell);
    }
    else
    {
        battlefield->logEvent(name + " (" + symbol + ") moved to (" +
                              std::to_string(x) + ", " + std::to_string(y) +
                              ")");
    }

    battlefield->getCell(xPos, yPos)->removeRobot();
    targetCell->placeRobot(shared_from_this());
    xPos = x;
    yPos = y;
}

void SteppingRobot::stomp(Direction direction)
{
    int newX = xPos;
    int newY = yPos;

    switch (direction)
    {
    case Direction::UP:
        newY += 1;
        break;
    case Direction::DOWN:
        newY -= 1;
        break;
    case Direction::LEFT:
        newX -= 1;
        break;
    case Direction::RIGHT:
        newX += 1;
        break;
    case Direction::UP_RIGHT:
        newX += 1;
        newY += 1;
        break;
    case Direction::DOWN_RIGHT:
        newX += 1;
        newY -= 1;
        break;
    case Direction::DOWN_LEFT:
        newX -= 1;
        newY -= 1;
        break;
    case Direction::UP_LEFT:
        newX -= 1;
        newY += 1;
        break;
    }

    stomp(newX, newY);
}
