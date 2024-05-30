#pragma once

#include <memory>
#include <string>

class Battlefield;

/**
 * @class Robot
 *
 * @brief An abstract base class that must be inherited by every abstract
 * subtype (SeeingRobot, ShootingRobot, SteppingRobot, MovingRobot).
 */
class Robot : public std::enable_shared_from_this<Robot>
{
    public:
        /**
         * @brief Constructs a Robot object.
         *
         * @param name The name of the robot.
         * @param xPos The initial x-coordinate of the robot.
         * @param yPos The initial y-coordinate of the robot.
         * @param symbol The symbol representing the robot.
         */
        Robot(std::string name, int xPos, int yPos, std::string symbol);

        /**
         * @brief Populates the battlefield member. This should only ever be
         * called in the main file during setup.
         *
         * @param battlefield A shared pointer to the battlefield.
         */
        void addBattlefield(std::shared_ptr<Battlefield> battlefield);

        /**
         * @brief Executes the robot's action plan.
         *
         * This function will execute when it's the robot's turn. Think of this
         * as the robot's main function. All battlefield actions like shooting,
         * moving, and stepping happen here.
         *
         * This is a pure virtual function that must be implemented by concrete
         * robot classes. Abstract subtypes don't have to implement this.
         */
        virtual void executeActionPlan() = 0;

        /**
         * @brief Upgrades the robot.
         *
         * By default, this function simply returns `nullptr`. If your robot can
         * upgrade to different robot types, override this function and have it
         * return a shared pointer to the new robot. Supply identical arguments
         * to the upgraded robot as you did with initial robot.
         *
         * @note If your robot requires, for example, requires 3 kills to
         * upgrade, the checking must be done here by looking at `killCount`. If
         * the criteria for upgrade is not met, return `nullptr`.
         *
         * @return A shared pointer to the upgraded robot.
         */
        virtual std::shared_ptr<Robot> upgrade();

        virtual ~Robot() = default;

        /**
         * @brief Gets the name of the robot.
         *
         * @return The name of the robot.
         */
        std::string getName() const;

        /**
         * @brief Gets the x-coordinate of the robot.
         *
         * @return The x-coordinate of the robot.
         */
        int getXPos() const;

        /**
         * @brief Gets the y-coordinate of the robot.
         *
         * @return The y-coordinate of the robot.
         */
        int getYPos() const;

        /**
         * @brief Sets the x-coordinate of the robot.
         *
         * @param xPos The new x-coordinate of the robot.
         */
        void setXPos(int xPos);

        /**
         * @brief Sets the y-coordinate of the robot.
         *
         * @param yPos The new y-coordinate of the robot.
         */
        void setYPos(int yPos);

        /**
         * @brief Gets the symbol representing the robot.
         *
         * @return The symbol representing the robot.
         */
        std::string getSymbol() const;

        /**
         * @brief Gets the number of lives the robot has.
         *
         * @return The number of lives the robot has.
         */
        int getLives() const;

        /**
         * @brief Decrements the number of lives the robot has by one.
         */
        void decrementLives();

        /**
         * @brief Increments the robot's kill count by one.
         */
        void incrementKillCount();

    protected:
        std::string name;
        int xPos;
        int yPos;
        std::string symbol;
        std::shared_ptr<Battlefield> battlefield;
        int lives;
        int killCount;
};
