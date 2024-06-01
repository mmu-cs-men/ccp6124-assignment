#include "Robot.h"
#include "../../util/Battlefield.h"
#include <memory>
#include <string>

Robot::Robot(std::string name, int xPos, int yPos, std::string symbol)
    : name(name), xPos(xPos), yPos(yPos), symbol(symbol), lives(3), killCount(0)
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
