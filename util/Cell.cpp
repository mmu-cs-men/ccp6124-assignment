/**********|**********|**********|
Program: Cell.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#include "Cell.h"

Cell::Cell(int x, int y) : robot(nullptr), x(x), y(y)
{
}

bool Cell::isOccupied() const
{
    return robot != nullptr;
}

void Cell::placeRobot(std::shared_ptr<Robot> newRobot)
{
    robot = newRobot;
}

void Cell::removeRobot()
{
    robot = nullptr;
}

std::shared_ptr<Robot> Cell::getRobot() const
{
    return robot;
}

std::string Cell::getSymbol() const
{
    return robot ? robot->getSymbol() : " ";
}

int Cell::getX() const
{
    return x;
}

int Cell::getY() const
{
    return y;
}
