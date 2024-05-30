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
