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