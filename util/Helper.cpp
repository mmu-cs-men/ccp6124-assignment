#include "Helper.h"
#include <exception>
#include <fstream>
#include <random>

int Helper::generateRandomNumber(int a, int b)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distr(a, b);

    return distr(engine);
}

void Helper::appendStrToFile(std::string str, std::string filePath)
{
    std::ofstream outFile(filePath, std::ios_base::app);
    if (!outFile)
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }
    outFile << str;
    outFile.close();
}
