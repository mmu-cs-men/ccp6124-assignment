#include "Helper.h"
#include <random>

int Helper::generateRandomNumber(int a, int b)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distr(a, b);

    return distr(engine);
}
