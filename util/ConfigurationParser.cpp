/**********|**********|**********|
Program: ConfigurationParser.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

/*
IMPORTANT NOTE
--------------
Please follow the format specified in the assignment instructions for the config
file. Do not deviate from the format AT ALL such as including line breaks.
Errors and undefined behaviour will result. The parser pretty much has no
error checking.
*/

#include "ConfigurationParser.h"
#include "../robots/BlueThunder.h"
#include "../robots/DVDShuriken.h"
#include "../robots/Landmine.h"
#include "../robots/Madbot.h"
#include "../robots/RoboCop.h"
#include "../robots/RoboTank.h"
#include "../robots/SniperBot.h"
#include "../robots/Terminator.h"
#include "../robots/TerminatorRoboCop.h"
#include "../robots/UltimateRobot.h"
#include "Helper.h"

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

    if (xDim * yDim < robotNum)
    {
        throw std::runtime_error(
            "Battlefield is too small to contain all robots");
    }

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
    int x = (xPos == "random") ? Helper::generateRandomNumber(0, xDim - 1)
                               : std::stoi(xPos);
    int y = (yPos == "random") ? Helper::generateRandomNumber(0, yDim - 1)
                               : std::stoi(yPos);

    // This will repeat if there are more than 94 robots, but I feel like nobody
    // will add that many.
    std::string robotSymbol(1, 'A' + (robots.size() % 94));

    if (type == "Terminator")
    {
        return std::make_shared<Terminator>(name, x, y, robotSymbol,
                                            "Terminator");
    }
    else if (type == "RoboCop")
    {
        return std::make_shared<RoboCop>(name, x, y, robotSymbol, "RoboCop");
    }
    else if (type == "TerminatorRoboCop")
    {
        return std::make_shared<TerminatorRoboCop>(name, x, y, robotSymbol,
                                                   "TerminatorRoboCop");
    }
    else if (type == "BlueThunder")
    {
        return std::make_shared<BlueThunder>(name, x, y, robotSymbol,
                                             "BlueThunder");
    }
    else if (type == "Madbot")
    {
        return std::make_shared<Madbot>(name, x, y, robotSymbol, "Madbot");
    }
    else if (type == "RoboTank")
    {
        return std::make_shared<RoboTank>(name, x, y, robotSymbol, "RoboTank");
    }
    else if (type == "UltimateRobot")
    {
        return std::make_shared<UltimateRobot>(name, x, y, robotSymbol,
                                               "UltimateRobot");
    }
    else if (type == "Landmine")
    {
        return std::make_shared<Landmine>(name, x, y, robotSymbol, "Landmine");
    }
    else if (type == "SniperBot")
    {
        return std::make_shared<SniperBot>(name, x, y, robotSymbol,
                                           "SniperBot");
    }
    else if (type == "DVDShuriken")
    {
        return std::make_shared<DVDShuriken>(name, x, y, robotSymbol,
                                             "DVDShuriken");
    }
    else
    {
        throw std::runtime_error("Unknown robot type: " + type);
    }
}
