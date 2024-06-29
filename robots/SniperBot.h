/**********|**********|**********|
Program: SniperBot.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|**********/

#pragma once

#include "base/MovingRobot.h"
#include "base/SeeingRobot.h"
#include "base/ShootingRobot.h"

class SniperBot : public MovingRobot, public SeeingRobot, public ShootingRobot
{
    public:
        SniperBot(std::string name, int xPos, int yPos, std::string symbol,
                  std::string type);
        void executeActionPlan() override;
};
