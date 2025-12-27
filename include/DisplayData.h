#pragma once

#include <array>
#include <bitset>
#include <vector>
class DisplayData {
public:
    static constexpr unsigned int DisplayWidth = 64;
    static constexpr unsigned int DisplayHeight = 32;
private:
    std::array<std::bitset<DisplayWidth>, DisplayHeight> displayData{};
public:
    //Returns did the collision occur
    bool Draw(const std::vector<uint8_t> &spriteData, uint8_t xPos, uint8_t yPos);
};
