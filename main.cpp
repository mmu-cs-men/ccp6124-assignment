/**********|**********|**********|
Program: main.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Sivananthan Seliyan
ID: 1221102320
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102320student.mmu.edu.my
Phone: 012-364-0956
**********|**********|**********/

#include "robots/Terminator.h"
#include "robots/base/Robot.h"
#include "util/Battlefield.h"
#include "util/ConfigurationParser.h"
#include <memory>

// clang-format off

// Harris:
// Compile command:
// If you're on Linux/Git Bash/Mac, you may use this command:
// g++ $(find . -name "*.cpp") -o main
//
// If you are on Windows and running in Powershell, this command probably works
// but I haven't tested it because I'm on Linux:
// g++ (Get-ChildItem -Recurse -Filter *.cpp).FullName -o main.exe

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
