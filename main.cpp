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
#include "util/SplashScreen.h"
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

    SplashScreen::display(xDim, yDim, maxSteps, robotNum, robots);
    std::cout << std::endl;

    std::cout << "Please select what would you like to do:" << std::endl;
    std::cout << "1. Run simulation step-by-step" << std::endl;
    std::cout << "2. Run simulation as fast as possible" << std::endl;
    std::cout << "3. Quit program" << std::endl << std::endl;

    while (true)
    {
        int input;
        std::cout << "Input: ";
        std::cin >> input;

        switch (input)
        {
        case 1:
            battlefield->runSimulation(false);
            return 0;
        case 2:
            battlefield->runSimulation(true);
            return 0;
        case 3:
            return 0;
        default:
            std::cout << "\nInvalid input! Try again." << std::endl;
        }
    }
}
