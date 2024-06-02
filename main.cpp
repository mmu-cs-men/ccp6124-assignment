/**********|**********|**********|
Program: main.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "robots/Terminator.h"
#include "robots/base/Robot.h"
#include "util/Battlefield.h"
#include "util/ConfigurationParser.h"
#include <memory>

// clang-format off
// g++ main.cpp util/Battlefield.cpp robots/base/Robot.cpp robots/Terminator.cpp util/Cell.cpp util/Helper.cpp robots/base/SeeingRobot.cpp robots/base/SteppingRobot.cpp util/ConfigurationParser.cpp -o main
// clang-format on

int main()
{
    ConfigurationParser parser("config.txt");
    int xDim = parser.getXDim();
    int yDim = parser.getYDim();
    int maxSteps = parser.getMaxSteps();
    int robotNum = parser.getRobotNum();
    DynamicArray<std::shared_ptr<Robot>> robots = parser.getRobots();

    auto battlefield = std::make_shared<Battlefield>(xDim, yDim, maxSteps);

    for (auto &robot : robots)
    {
        robot->addBattlefield(battlefield);
        battlefield->addRobot(robot);
    }

    // TODO: Add splash screen here

    battlefield->runSimulation(false);
}
