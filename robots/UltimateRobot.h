/**********|**********|**********|
Program: UltimateRobot.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#pragma once

#include "base/SeeingRobot.h"
#include "base/ShootingRobot.h"
#include "base/SteppingRobot.h"

class UltimateRobot : public SeeingRobot,
                      public ShootingRobot,
                      public SteppingRobot
{
    public:
        UltimateRobot(std::string name, int xPos, int yPos, std::string symbol,
                      std::string type);
        void executeActionPlan() override;
};
