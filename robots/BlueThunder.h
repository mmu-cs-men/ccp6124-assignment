/**********|**********|**********|
Program: BlueThunder.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai A/L Ramesh Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 12211020080@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#pragma once

#include "../util/CircularLinkedList.h"
#include "../util/Direction.h"
#include "base/ShootingRobot.h"

class BlueThunder :  public ShootingRobot
{
    public:
        BlueThunder(std::string name, int xPos, int yPos, std::string symbol,
                    std::string type);
        void executeActionPlan() override;

private:
    CircularLinkedList<Direction> directions;
    Direction currentDirection;
    
};