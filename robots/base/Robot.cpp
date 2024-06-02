/**********|**********|**********|
Program: Robot.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "Robot.h"
#include "../../util/Battlefield.h"
#include <memory>
#include <string>

Robot::Robot(std::string name, int xPos, int yPos, std::string symbol,
             std::string type)
    : name(name), xPos(xPos), yPos(yPos), symbol(symbol), type(type), lives(3),
      killCount(0)
{
}

void Robot::addBattlefield(std::shared_ptr<Battlefield> battlefield)
{
    this->battlefield = battlefield;
}

std::string Robot::getName() const
{
    return name;
}

int Robot::getXPos() const
{
    return xPos;
}

int Robot::getYPos() const
{
    return yPos;
}

void Robot::setXPos(int xPos)
{
    this->xPos = xPos;
}

void Robot::setYPos(int yPos)
{
    this->yPos = yPos;
}

std::string Robot::getSymbol() const
{
    return symbol;
}

int Robot::getLives() const
{
    return lives;
}

void Robot::decrementLives()
{
    lives--;
}

std::shared_ptr<Robot> Robot::upgrade()
{
    return nullptr;
}

void Robot::incrementKillCount()
{
    killCount++;
}
