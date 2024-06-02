/**********|**********|**********|
Program: Terminator.h
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

#include "../util/Direction.h"
#include "../util/Helper.h"
#include "base/SeeingRobot.h"
#include "base/SteppingRobot.h"

class Terminator : public SeeingRobot, public SteppingRobot
{
    public:
        Terminator(std::string name, int xPos, int yPos, std::string symbol,
                   std::string type);
        void executeActionPlan() override;
        std::shared_ptr<Robot> upgrade() override;
};
