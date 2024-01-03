#include "random.hpp"

std::random_device Random::randomDevice;

double Random::getReal(double a, double b) {
    std::mt19937 generator(randomDevice());
    std::uniform_real_distribution<> distribution(a, b);

    return distribution(generator);
}

int Random::getInt(int a, int b) {
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution(a, b);

    return distribution(generator);
}