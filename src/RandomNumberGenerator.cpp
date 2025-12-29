#include "RandomNumberGenerator.h"

namespace rng {
    uint8_t GetRandomValue() {
        std::random_device randomDevice;
        std::mt19937 generator{randomDevice()};
        return static_cast<uint8_t>(generator() & 0xFF);
    }
}

