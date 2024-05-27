#include "../../util/Direction.h"
#include "Robot.h"
#include <string>

class MovingRobot : virtual public Robot
{
    public:
        MovingRobot(std::string name, int xPos, int yPos, std::string symbol);
        void move(int x, int y);
        void move(Direction direction);
};
