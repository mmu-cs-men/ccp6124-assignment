#pragma once

#include "../robots/base/Robot.h"
#include "DynamicArray.h"
#include <fstream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

/**
 * @class ConfigurationParser
 *
 * @brief Parses configuration files to initialize simulation parameters and
 * robots.
 *
 * This class reads a configuration file to set up the dimensions of the
 * battlefield, the maximum number of steps for the simulation, the number of
 * robots, and the robots themselves.
 */
class ConfigurationParser
{
    public:
        /**
         * @brief Constructs a ConfigurationParser object and parses the given
         * file.
         *
         * @param filePath The path to the configuration file.
         *
         * @throws std::runtime_error if the file cannot be opened.
         */
        ConfigurationParser(const std::string &filePath);

        /**
         * @brief Gets the x-dimension of the battlefield.
         *
         * @return The x-dimension of the battlefield.
         */
        int getXDim() const;

        /**
         * @brief Gets the y-dimension of the battlefield.
         *
         * @return The y-dimension of the battlefield.
         */
        int getYDim() const;

        /**
         * @brief Gets the maximum number of steps for the simulation.
         *
         * @return The maximum number of steps.
         */
        int getMaxSteps() const;

        /**
         * @brief Gets the number of robots specified in the configuration.
         *
         * @return The number of robots.
         */
        int getRobotNum() const;

        /**
         * @brief Gets the list of robots initialized from the configuration
         * file.
         *
         * @return A DynamicArray of shared pointers to Robot objects.
         */
        DynamicArray<std::shared_ptr<Robot>> getRobots() const;

    private:
        int xDim;
        int yDim;
        int maxSteps;
        int robotNum;
        DynamicArray<std::shared_ptr<Robot>> robots;

        /**
         * @brief Creates a robot based on the given parameters.
         *
         * @param type The type of the robot (e.g., "Terminator").
         * @param name The name of the robot.
         * @param xPos The x-position of the robot (can be "random").
         * @param yPos The y-position of the robot (can be "random").
         *
         * @return A shared pointer to the created Robot object.
         *
         * @throws std::runtime_error if the robot type is unknown.
         */
        std::shared_ptr<Robot> createRobot(const std::string &type,
                                           const std::string &name,
                                           const std::string &xPos,
                                           const std::string &yPos);
};
