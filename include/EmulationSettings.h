#pragma once

#include <SFML/Graphics/Color.hpp>
#include <array>

struct EmulationSettings {
    int MaxInstructionsPerSecond = 60;

    float BackgroundColor[4]{0.0, 0.0, 0.0, 1.0};
    float PixelColor[4]{1.0, 1.0, 1.0, 1.0};
};
