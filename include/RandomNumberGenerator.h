#pragma once

#include <random>

class RandomNumberGenerator {
public:
    uint8_t GetRandomValue();
private:
    std::random_device randomDevice;
    std::mt19937 generator{randomDevice()};

};
