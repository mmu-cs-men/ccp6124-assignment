#include "robots/Terminator.h"
#include "robots/base/Robot.h"
#include "util/Battlefield.h"
#include <memory>

int main()
{
    Battlefield battlefield(10, 10, 100);
    std::shared_ptr<Battlefield> pBattlefield =
        std::make_shared<Battlefield>(battlefield);

    std::shared_ptr<Robot> robot1 =
        std::make_shared<Terminator>("Zedd", 5, 5, "🤖");
    std::shared_ptr<Robot> robot2 =
        std::make_shared<Terminator>("Star", 1, 3, "❤️");

    robot1->addBattlefield(pBattlefield);
    robot2->addBattlefield(pBattlefield);

    pBattlefield->addRobot(robot1);
    pBattlefield->addRobot(robot2);

    pBattlefield->runSimulation(false);
}
