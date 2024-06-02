/**********|**********|**********|
Program: Helper.h
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

#include <string>

/**
 * @class Helper
 * @brief A utility class providing helper functions.
 *
 * This class contains static methods that can be used for various utility
 * purposes. I thought this class would be much bigger when I made it but it
 * seems like it's just random number generation. Oh well.
 */
struct Helper
{
        /**
         * @brief Generates a random integer between the closed interval [a, b].
         *
         * I feel like this is pretty self-explanatory.
         *
         * @param a The lower bound of the range (inclusive).
         * @param b The upper bound of the range (inclusive).
         * @return A random integer between a and b.
         *
         * @throws std::invalid_argument if a is greater than b.
         *
         * @note Edge cases:
         * - If a == b, the function will always return a (or b, since they are
         * equal).
         * - If a > b, the function will segfault, don't be a dummy.
         */
        static int generateRandomNumber(int a, int b);

        /**
         * @brief Appends a string to the log file.
         *
         * This method appends the given string to the log file. If the log
         * count is zero, it updates the log count first. The log file is named
         * based on the current log count (how many log files exist already) and
         * is located in the "logs" directory.
         *
         * @param str The string to append to the log file.
         *
         * @throws std::runtime_error if the file cannot be opened.
         */
        static void appendStrToLogFile(std::string str);

        /**
         * @brief Updates the log count based on existing log files.
         *
         * This method creates the "logs" directory if it does not exist and
         * iterates through the log files in the directory to determine the
         * highest log number. The log count is then set to one more than the
         * highest log number.
         */
        static void updateLogCount();

        static int logCount;
};
