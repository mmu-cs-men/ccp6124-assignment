#include "robots/Terminator.h"
#include "robots/base/Robot.h"
#include "util/Battlefield.h"
#include "util/ConfigurationParser.h"
#include <memory>

// clang-format off
// g++ main.cpp util/Battlefield.cpp robots/base/Robot.cpp robots/Terminator.cpp util/Cell.cpp util/Helper.cpp robots/base/SeeingRobot.cpp robots/base/SteppingRobot.cpp -o main
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
