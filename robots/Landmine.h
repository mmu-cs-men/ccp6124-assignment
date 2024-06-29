/**********|**********|**********|
Program: Landmine.h
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

#include "base/ShootingRobot.h"

class Landmine : public ShootingRobot
{
    public:
        Landmine(std::string name, int xPos, int yPos, std::string symbol,
                 std::string type);
        void executeActionPlan() override;
};