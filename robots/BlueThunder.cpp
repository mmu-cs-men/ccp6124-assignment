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
#include "Madbot.h"

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
    try
    {
        fire(currentDirection);
        currentDirection = directions.next(currentDirection);
    }
    catch (const std::out_of_range &e)
    {
        currentDirection = directions.next(currentDirection);
        executeActionPlan();
        return;
    }
}

std::shared_ptr<Robot> BlueThunder::upgrade()
{
    if (killCount >= 3)
    {
        std::shared_ptr<Madbot> upgradedRobot =
            std::make_shared<Madbot>(name, xPos, yPos, symbol, "Madbot");

        upgradedRobot->addBattlefield(battlefield);

        return upgradedRobot;
    }
    return nullptr;
}
