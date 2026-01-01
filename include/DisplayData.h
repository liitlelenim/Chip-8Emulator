#pragma once

#include <array>
#include <bitset>
#include <vector>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Color.hpp"

class EmulationSettings;
class DisplayData {
public:
    static constexpr sf::Color PixelOnColor = sf::Color::White;
    static constexpr sf::Color PixelOffColor = sf::Color::Black;
    static constexpr unsigned int DisplayWidth = 64;
    static constexpr unsigned int DisplayHeight = 32;
private:
    std::array<std::bitset<DisplayWidth>, DisplayHeight> displayData{};
    const EmulationSettings& emulationSettings;
public:
    explicit DisplayData(const EmulationSettings& emulationSettings);
    //Returns did the collision occur
    bool Draw(const std::vector<uint8_t> &spriteData, uint8_t xPos, uint8_t yPos);

    void Clear();

    sf::Texture GetDisplayTexture() const;
};
