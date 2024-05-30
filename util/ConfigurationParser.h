#pragma once

#include "../robots/base/Robot.h"
#include "DynamicArray.h"
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

class ConfigurationParser
{
    public:
        ConfigurationParser(const std::string &filePath);
        int getXDim() const;
        int getYDim() const;
        int getMaxSteps() const;
        int getRobotNum() const;
        DynamicArray<std::shared_ptr<Robot>> getRobots() const;

    private:
        int xDim;
        int yDim;
        int maxSteps;
        int robotNum;
        DynamicArray<std::shared_ptr<Robot>> robots;
        std::shared_ptr<Robot> createRobot(const std::string &type,
                                           const std::string &name,
                                           const std::string &xPos,
                                           const std::string &yPos);
};
