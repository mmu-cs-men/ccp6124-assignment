#pragma once

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
};
