/**********|**********|**********|
Program: Landmine.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#include "Landmine.h"
#include "../util/Direction.h"

Landmine::Landmine(std::string name, int xPos, int yPos, std::string symbol,
                   std::string type)
    : ShootingRobot(name, xPos, yPos, symbol, type),
      Robot(name, xPos, yPos, symbol, type)
{
}

void Landmine::executeActionPlan()
{
    for (int i = 0; i < 8; i++)
    {
        try
        {
            fire(static_cast<Direction>(i));
        }
        catch (...)
        {
            // Ignore out of bounds exceptions
        }
    }
}