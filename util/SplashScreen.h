/**********|**********|**********|
Program: SplashScreen.h
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Laxman Pillai
ID: 1221102008
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102008@student.mmu.edu.my
Phone: 012-525-8246
**********|**********|**********/

#pragma once

#include "../robots/base/Robot.h"
#include "DynamicArray.h"
#include <memory>

/**
 * @class SplashScreen
 * @brief A utility class for displaying the splash screen.
 */
struct SplashScreen
{
        static void display(int xDim, int yDim, int maxSteps, int robotNum,
                            DynamicArray<std::shared_ptr<Robot>> robots);
};
