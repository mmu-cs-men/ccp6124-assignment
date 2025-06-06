/**********|**********|**********|
Program: ShootingRobot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|**********/

#include "ShootingRobot.h"
#include "../../util/Battlefield.h"
#include <stdexcept>

ShootingRobot::ShootingRobot(std::string name, int xPos, int yPos,
                             std::string symbol, std::string type)
    : Robot(name, xPos, yPos, symbol, type)
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

void ShootingRobot::fire(Direction direction)
{
    int dx = 0;
    int dy = 0;

    switch (direction)
    {
    case Direction::UP:
        dy += 1;
        break;
    case Direction::DOWN:
        dy -= 1;
        break;
    case Direction::LEFT:
        dx -= 1;
        break;
    case Direction::RIGHT:
        dx += 1;
        break;
    case Direction::UP_RIGHT:
        dx += 1;
        dy += 1;
        break;
    case Direction::DOWN_RIGHT:
        dx += 1;
        dy -= 1;
        break;
    case Direction::DOWN_LEFT:
        dx -= 1;
        dy -= 1;
        break;
    case Direction::UP_LEFT:
        dx -= 1;
        dy += 1;
        break;
    }

    fire(dx, dy);
}