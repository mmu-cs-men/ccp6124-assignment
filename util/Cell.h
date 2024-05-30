#pragma once

#include "../robots/base/Robot.h"
#include <memory>

/**
 * @class Cell
 *
 * @brief Represents a cell on the battlefield grid.
 *
 * This class manages the state of a cell, including its coordinates and the
 * robot occupying it.
 */
class Cell
{
    public:
        /**
         * @brief Constructs a Cell object with specified coordinates.
         *
         * @param x The x-coordinate of the cell.
         * @param y The y-coordinate of the cell.
         *
         * Initializes the cell with no robot.
         */
        Cell(int x, int y);

        /**
         * @brief Checks if the cell is occupied by a robot.
         *
         * @return True if the cell is occupied, false otherwise.
         */
        bool isOccupied() const;

        /**
         * @brief Places a robot in the cell.
         *
         * @param newRobot A shared pointer to the robot to be placed in the
         * cell.
         *
         * @note Replaces any existing robot in the cell with the new robot. Use
         * with care!
         */
        void placeRobot(std::shared_ptr<Robot> newRobot);

        /**
         * @brief Removes the robot from the cell.
         *
         * Sets the cell's robot to nullptr, indicating it is unoccupied.
         */
        void removeRobot();

        /**
         * @brief Gets the robot occupying the cell.
         *
         * @return A shared pointer to the robot occupying the cell, or nullptr
         * if the cell is unoccupied.
         */
        std::shared_ptr<Robot> getRobot() const;

        /**
         * @brief Gets the symbol representing the robot in the cell.
         *
         * @return The symbol of the robot if the cell is occupied, otherwise a
         * space character. The space character is a quick and dirty solution
         * for printing empty cells in the battlefield.
         */
        std::string getSymbol() const;

        /**
         * @brief Gets the x-coordinate of the cell.
         *
         * @return The x-coordinate of the cell.
         */
        int getX() const;

        /**
         * @brief Gets the y-coordinate of the cell.
         *
         * @return The y-coordinate of the cell.
         */
        int getY() const;

    private:
        std::shared_ptr<Robot> robot;
        int x;
        int y;
};
