#pragma once

#include <SFML/Graphics/Color.hpp>

struct EmulationSettings {
    int MaxInstructionsPerSecond = 60;
    sf::Color BackgroundColor{sf::Color::Black};
    sf::Color PixelColor{sf::Color::White};
};
