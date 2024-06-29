/**********|**********|**********|
Program: MadBot.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Hawash, Abdullah
ID: 1221102209
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102209@student.mmu.edu.my
Phone: 017-250-3208
**********|**********|***********/

#pragma once

#include "base/ShootingRobot.h"

class Madbot : public ShootingRobot
{
    public:
        Madbot(const std::string &name, int x, int y, const std::string &symbol,
               const std::string &type);
        virtual void executeActionPlan() override;

    private:
        bool isValidTarget(int dx, int dy);
};
