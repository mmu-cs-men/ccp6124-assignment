/**********|**********|**********|
Program: MovingRobot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "MovingRobot.h"
#include "../../util/Battlefield.h"

MovingRobot::MovingRobot(std::string name, int xPos, int yPos,
                         std::string symbol)
    : Robot(name, xPos, yPos, symbol)
{
}

void MovingRobot::move(int x, int y)
{
    if (abs(x - xPos) > 1 || abs(y - yPos) > 1)
    {
        throw std::invalid_argument(name + " (" + symbol +
                                    ") attempted an illegal move");
    }
    else if (x < 0 || x >= battlefield->getXDim() || y < 0 ||
             y >= battlefield->getYDim())
    {
        battlefield->logEvent(name + " (" + symbol +
                              ") attempted to move out of battlefield");
        return;
    }
    else if (battlefield->getCell(x, y)->isOccupied())
    {
        battlefield->logEvent(name + " (" + symbol +
                              ") attempted to move to an occupied cell");
        return;
    }

    battlefield->getCell(xPos, yPos)->removeRobot();
    battlefield->getCell(x, y)->placeRobot(shared_from_this());
    xPos = x;
    yPos = y;

    battlefield->logEvent(name + " (" + symbol + ") moved to (" +
                          std::to_string(x) + ", " + std::to_string(y) + ")");
}

void MovingRobot::move(Direction direction)
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

    move(newX, newY);
}
