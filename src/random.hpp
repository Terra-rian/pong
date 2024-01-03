#pragma once

#include "globals.hpp"

/**
 * @brief A utility class to generate random numbers.
 */
class Random {
    public:
    /**
     * @brief Returns a double between "a" and "b".
     * @param a The minimum number possible.
     * @param b The maximum number possible.
     */
    static double getReal(double a, double b);

    /**
     * @brief Returns an integer between "a" and "b".
     * @param a The minimum number possible.
     * @param b The maximum number possible.
     */
    [[maybe_unused]] static int getInt(int a, int b);

    private:
    /**
     * @brief The generator to generate random numbers.
     */
    static std::random_device randomDevice;
};