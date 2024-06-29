/**********|**********|**********|
Program: DVDShuriken.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102008@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#pragma once

#include "base/SteppingRobot.h"
#include <memory>

class DVDShuriken : public SteppingRobot
{
    public:
        DVDShuriken(std::string name, int xPos, int yPos, std::string symbol,
                    std::string type);
        void executeActionPlan() override;

    private:
        std::unique_ptr<int> lastDx;
        std::unique_ptr<int> lastDy;
};
