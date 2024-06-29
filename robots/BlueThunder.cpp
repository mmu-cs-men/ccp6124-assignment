/**********|**********|**********|
Program: BlueThunder.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai A/L Ramesh Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 12211020080@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#include "BlueThunder.h"
#include "../util/Battlefield.h"
#include "../util/Helper.h"

BlueThunder::BlueThunder(std::string name, int xPos, int yPos,
                         std::string symbol, std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
    // Initialize directions in clockwise order
    directions.append(Direction::UP);
    directions.append(Direction::UP_RIGHT);
    directions.append(Direction::RIGHT);
    directions.append(Direction::DOWN_RIGHT);
    directions.append(Direction::DOWN);
    directions.append(Direction::DOWN_LEFT);
    directions.append(Direction::LEFT);
    directions.append(Direction::UP_LEFT);
    currentDirection = directions.getHead();
}

void BlueThunder::executeActionPlan()
{
    // Fire in the current direction
    Direction dir = currentDirection;
    int dx = 0;
    int dy = 0;
    switch (dir)
    {
    case Direction::UP:
        dy = 1;
        break;
    case Direction::UP_RIGHT:
        dx = 1;
        dy = 1;
        break;
    case Direction::RIGHT:
        dx = 1;
        break;
    case Direction::DOWN_RIGHT:
        dx = 1;
        dy = -1;
        break;
    case Direction::DOWN:
        dy = -1;
        break;
    case Direction::DOWN_LEFT:
        dx = -1;
        dy = -1;
        break;
    case Direction::LEFT:
        dx = -1;
        break;
    case Direction::UP_LEFT:
        dx = -1;
        dy = 1;
        break;
    }

    int newX = xPos + dx;
    int newY = yPos + dy;

    // Move to the next direction
    if (newX >= battlefield->getXDim() || newY >= battlefield->getYDim())
    {
        currentDirection = directions.next(currentDirection);
        executeActionPlan();
        return;
    }

    currentDirection = directions.next(currentDirection);
    fire(dx, dy);
}
