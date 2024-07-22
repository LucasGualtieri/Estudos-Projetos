#ifndef UTILS_HPP
#define UTILS_HPP

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

/**
 * Generates a random integer within a specified range.
 *
 * @param min The minimum value of the random integer (default: 0).
 * @param max The maximum value of the random integer (default: INT_MAX).
 * @param seed The seed value for the random number generator (default: 0).
 *             If set to 0, uses the current time as seed.
 * @return A random integer between `min` (inclusive) and `max` (inclusive).
 */
inline int randomInt(int min = 0, int max = INT_MAX, int seed = 0) {

    static bool SEED_SET = false;

    if (!SEED_SET || seed != 0) {

        SEED_SET = true;

        if (seed == 0) srand(time(nullptr));
        else srand(seed);
    }

	return (rand() % ((max + 1) - min)) + min;
}

inline int readInt(const std::string& prompt = "") {
    std::string input;
    int number;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        try {
            // Attempt to convert the input to an integer
            size_t pos;
            number = std::stoi(input, &pos);

            // Check if the entire string was a valid number
            if (pos == input.length()) {
                break;
            } else {
                std::cout << "Invalid input, please enter a valid integer: ";
            }
        } catch (const std::invalid_argument&) {
            // Catch invalid_argument exception if input is not an integer
            std::cout << "Invalid input, please enter a valid integer: ";
        } catch (const std::out_of_range&) {
            // Catch out_of_range exception if the number is too large
            std::cout << "Input is out of range, please enter a valid integer: ";
        }
    }

    return number;
}

inline void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__unix__) || defined(__APPLE__) || defined(__linux__)
        system("clear");
    #else
        cout << "Clear screen not supported on this OS" << endl;
    #endif
}

#endif
