#include "SeeingRobot.h"

SeeingRobot::SeeingRobot(std::string name, int xPos, int yPos,
                         std::string symbol)
    : Robot(name, xPos, yPos, symbol)
{
}

std::array<std::array<std::shared_ptr<Cell>, 3>, 3> SeeingRobot::look(int dx,
                                                                      int dy)
{
    int newXPos = dx + xPos;
    int newYPos = dy + yPos;
    std::array<std::array<std::shared_ptr<Cell>, 3>, 3> visionGrid;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int checkX = newXPos - 1 + i;
            int checkY = newYPos - 1 + j;
            if (checkX < 0 || checkX >= battlefield->getXDim() || checkY < 0 ||
                checkY >= battlefield->getYDim() ||
                (checkX == xPos && checkY == yPos))
            {
                visionGrid[i][j] = nullptr;
            }
            else
            {
                visionGrid[i][j] = battlefield->getCell(checkX, checkY);
            }
        }
    }
    battlefield->logEvent(
        name + " (" + symbol + ") " + " performed a look action centered on " +
        "(" + std::to_string(newXPos) + ", " + std::to_string(newYPos) + ")");
    return visionGrid;
}
