/**********|**********|**********|
Program: Helper.cpp
Course: Object Oriented Programming and Data Structures
Trimester: 2410
Name: Harris Majeed
ID: 1221102800
Lecture Section: TC1L
Tutorial Section: TT1L
Email: 1221102800@student.mmu.edu.my
Phone: 017-366-6523
**********|**********|**********/

#include "Helper.h"
#include <exception>
#include <filesystem>
#include <fstream>
#include <random>

int Helper::logCount = 0;

int Helper::generateRandomNumber(int a, int b)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> distr(a, b);

    return distr(engine);
}

void Helper::appendStrToLogFile(std::string str)
{
    if (!logCount)
    {
        updateLogCount();
    }

    std::string filePath = "logs/" + std::to_string(logCount) + ".txt";

    std::ofstream outFile(filePath, std::ios_base::app);
    if (!outFile)
    {
        throw std::runtime_error("Unable to open file: " + filePath);
    }
    outFile << str;
    outFile.close();
}

void Helper::updateLogCount()
{
    std::filesystem::create_directory("logs");

    int highestNumber = 0;
    for (const auto &entry : std::filesystem::directory_iterator("logs"))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            try
            {
                int number = std::stoi(entry.path().stem().string());
                if (number > highestNumber)
                {
                    highestNumber = number;
                }
            }
            catch (const std::invalid_argument &e)
            {
                // Ignore impostor files
            }
        }
    }

    logCount = highestNumber + 1;
}
