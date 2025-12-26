#include "RandomNumberGenerator.h"

uint8_t RandomNumberGenerator::GetRandomValue() {
    return static_cast<uint8_t>(generator() & 0xFF);
}

