#include "ConfigurationParser.h"
#include "../robots/Terminator.h"

ConfigurationParser::ConfigurationParser(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    std::getline(file, line);
    std::istringstream dimStream(line.substr(line.find(':') + 1));
    dimStream >> xDim >> yDim;

    std::getline(file, line);
    maxSteps = std::stoi(line.substr(line.find(':') + 1));

    std::getline(file, line);
    robotNum = std::stoi(line.substr(line.find(':') + 1));

    for (int i = 0; i < robotNum; ++i)
    {
        std::getline(file, line);
        std::istringstream robotStream(line);
        std::string type, name, xPos, yPos;
        robotStream >> type >> name >> xPos >> yPos;
        robots.append(createRobot(type, name, xPos, yPos));
    }
}

int ConfigurationParser::getXDim() const
{
    return xDim;
}

int ConfigurationParser::getYDim() const
{
    return yDim;
}

int ConfigurationParser::getMaxSteps() const
{
    return maxSteps;
}

int ConfigurationParser::getRobotNum() const
{
    return robotNum;
}

DynamicArray<std::shared_ptr<Robot>> ConfigurationParser::getRobots() const
{
    return robots;
}

std::shared_ptr<Robot> ConfigurationParser::createRobot(const std::string &type,
                                                        const std::string &name,
                                                        const std::string &xPos,
                                                        const std::string &yPos)
{
    int x = (xPos == "random") ? rand() % xDim : std::stoi(xPos);
    int y = (yPos == "random") ? rand() % yDim : std::stoi(yPos);

    std::string robotSymbol(1, 'A' + (robots.size() % 94));

    if (type == "Terminator")
    {
        return std::make_shared<Terminator>(name, x, y, robotSymbol, type);
    }
    else
    {
        throw std::runtime_error("Unknown robot type: " + type);
    }
}
