#pragma once

#include "Cell.h"
#include "CircularLinkedList.h"
#include "DynamicArray.h"
#include "Queue.h"
#include <memory>
#include <string>

// Needed to avoid circular dependency
class Robot;

/**
 * @class Battlefield
 * @brief Manages the battlefield where robots compete.
 *
 * This class is responsible for initializing the battlefield, managing robots,
 * running the simulation, and logging events. It handles the addition, removal,
 * and respawn of robots, as well as the progression of simulation steps.
 */
class Battlefield
{
    public:
        /**
         * @brief Constructs a Battlefield object.
         *
         * @param xDim The width of the battlefield.
         * @param yDim The height of the battlefield.
         * @param maxSteps The maximum number of steps the simulation will run.
         *
         * Initializes the battlefield matrix with cells and sets the initial
         * step to 1.
         */
        Battlefield(int xDim, int yDim, int maxSteps);

        /**
         * @brief Adds a robot to the battlefield.
         *
         * @param robot A shared pointer to the robot to be added.
         *
         * Places the robot on the battlefield and sets it as the current robot
         * if no other robot is set.
         */
        void addRobot(std::shared_ptr<Robot> robot);

        /**
         * @brief Runs the simulation.
         *
         * @param asap If true, the simulation runs without waiting for user
         * input between steps.
         *
         * Runs the simulation until the maximum number of steps is reached or
         * only one robot remains. Displays the battlefield and logs events at
         * each step.
         */
        void runSimulation(bool asap);

        /**
         * @brief Gets a cell at the specified coordinates.
         *
         * @param x The x-coordinate of the cell.
         * @param y The y-coordinate of the cell.
         * @return A shared pointer to the cell at the specified coordinates.
         */
        std::shared_ptr<Cell> getCell(int x, int y) const;

        /**
         * @brief Logs an event.
         *
         * @param event The event message to be logged.
         *
         * Adds the event message to the event queue.
         */
        void logEvent(const std::string event);

        /**
         * @brief Gets the width of the battlefield.
         *
         * @return The width of the battlefield.
         */
        int getXDim() const;

        /**
         * @brief Gets the height of the battlefield.
         *
         * @return The height of the battlefield.
         */
        int getYDim() const;

        /**
         * @brief Kills a robot on the battlefield.
         *
         * @param killer A shared pointer to the robot that performs the kill.
         * @param cell A shared pointer to the cell where the robot to be killed
         * is located.
         *
         * Removes the robot from the cell and the list of robots. Also handles
         * upgrading the killer. If the killed robot has remaining lives, it is
         * added to the respawn queue. Also logs the kill event.
         *
         * @throws std::runtime_error if the cell is unoccupied.
         */
        void killRobot(std::shared_ptr<Robot> killer,
                       std::shared_ptr<Cell> cell);

    private:
        /**
         * @brief Advances to the next robot in the list.
         *
         * @throws std::runtime_error if no robots have been added.
         */
        void nextRobot();

        /**
         * @brief Constructs a string of the current state of the battlefield.
         *
         * @returns The battlefield matrix, the current step, the respawn queue,
         * and the event log a string.
         */
        std::string getBattlefieldString();

        /**
         * @brief Gets the number of participating robots.
         *
         * @return The number of robots currently participating in the
         * simulation, including robots in the respawn queue. Does not
         * include robots that have died and exhausted their lives.
         */
        int getParticipatingRobots() const;

        /**
         * @brief Respawns a robot from the respawn queue.
         *
         * Places the robot in a random unoccupied cell on the battlefield and
         * logs the respawn event.
         */
        void respawnRobot();

        Queue<std::shared_ptr<Robot>> respawnQueue;

        // Events are added to a queue instead of being printed directly.
        Queue<std::string> eventQueue;

        CircularLinkedList<std::shared_ptr<Robot>> robots;
        DynamicArray<DynamicArray<std::shared_ptr<Cell>>> battlefieldMatrix;
        std::shared_ptr<Robot> currentRobot;

        // Queue for symbols of dead robots. Kind of a crap solution but it's
        // the best I could think of at the time but it works and I'm too lazy
        // to change this.
        DynamicArray<std::string> respawnQueueStr;

        int xDim;
        int yDim;
        int maxSteps;
        int currentStep;
};
