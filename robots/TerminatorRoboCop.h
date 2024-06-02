/**********|**********|**********|
Program: TerminatorRoboCop.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#pragma once

#include "base/SeeingRobot.h"
#include "base/ShootingRobot.h"
#include "base/SteppingRobot.h"

class TerminatorRoboCop : public SeeingRobot,
                          public ShootingRobot,
                          public SteppingRobot
{
    public:
        TerminatorRoboCop(std::string name, int xPos, int yPos,
                          std::string symbol, std::string type);
        void executeActionPlan() override;
};
