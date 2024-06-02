/**********|**********|**********|
Program: SplashScreen.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102008@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#include "SplashScreen.h"
#include "../robots/base/Robot.h"
#include "ConfigurationParser.h"
#include <iomanip>
#include <iostream>

void SplashScreen::display(int xDim, int yDim, int maxSteps, int robotNum,
                           DynamicArray<std::shared_ptr<Robot>> robots)
{   system("cls");

    std::string star(100, '*');
    std::string line(70, '-');

    std::cout << std::endl;

    std::cout << "Welcome to Robot War Simulator.This is a game made for our "
                 "CPP6124 assignment\n";

    std::cout << "Based on the configuration file, the following settings will "
                 "be applied to your simulation\n\n";

    std::cout << star << std::endl;

    std::cout << "\nBattlefield Dimensions: " << xDim << "x" << yDim
              << std::endl;
    std::cout << "Steps: " << maxSteps << std::endl;
    std::cout << "Robots: " << robotNum << std::endl << std::endl;

    std::cout << "Robot List:" << std::endl;

    std::cout << line << std::endl;

    std::cout <<"NAME" 
              << std::setw(18) << std::right <<"TYPE"
              << std::setw(32) << "POSITION (x,y)" 
              << std::setw(12) << "SYMBOL\n";

    std::cout << line << std::endl;

     

    for (int i = 0; i < robots.size(); ++i)
    {
        auto robot = robots[i];
        std::cout << std::left << std::setw(18) << robot->getName()
                  << std::setw(22) <<"*******************"
                  << std::setw(19) << ("(" + std::to_string(robot->getXPos()) + "," +std::to_string(robot->getYPos()) + ")")
                  << robot->getSymbol() << "\n";
    }
    
    std::cout<<"\n"<<star<<std::endl;
}
