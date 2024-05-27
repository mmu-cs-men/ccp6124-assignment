#include "../../util/Cell.h"
#include "../../util/DynamicArray.h"
#include "Robot.h"
#include <array>

class SeeingRobot : virtual public Robot
{
    public:
        SeeingRobot(std::string name, int xPos, int yPos, std::string symbol);
        std::array<std::array<std::shared_ptr<Cell>, 3>, 3> look(int dx,
                                                                 int dy);
};
