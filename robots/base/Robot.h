#pragma once

#include <memory>
#include <string>

class Battlefield;

class Robot : public std::enable_shared_from_this<Robot>
{
    public:
        Robot(std::string name, int xPos, int yPos, std::string symbol);
        void addBattlefield(std::shared_ptr<Battlefield> battlefield);
        virtual void executeActionPlan() = 0;
        virtual std::shared_ptr<Robot> upgrade();
        virtual ~Robot() = default;
        std::string getName() const;
        int getXPos() const;
        int getYPos() const;
        void setXPos(int xPos);
        void setYPos(int yPos);
        std::string getSymbol() const;
        int getLives() const;
        void decrementLives();
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
