#include "DisplayData.h"
#include "SFML/Graphics/Image.hpp"

bool DisplayData::Draw(const std::vector<uint8_t> &spriteData, uint8_t xPos, uint8_t yPos) {
    xPos %= DisplayWidth;
    yPos %= DisplayHeight;
    bool collisionHappened = false;
    for (int y = yPos; y < yPos + spriteData.size(); y++) {
        for (int x = xPos; x < xPos + 8; x++) {
            bool initialBitVal = displayData[y][x];
            displayData[y][x] = displayData[y][x] ^ (0x80 & (spriteData[y - yPos] >> (x - xPos)));
            if (spriteData[y - yPos] & (0x80 >> (x - xPos))) {
                displayData[y][x] = !displayData[y][x];
            }
            bool disabledPixel = initialBitVal && !displayData[y][x];

            if (disabledPixel) {
                collisionHappened = true;
            }
        }
    }
    return collisionHappened;
}

void DisplayData::Clear() {
    displayData.fill(0);
}

sf::Texture DisplayData::GetDisplayTexture() const {
    sf::Image displayImage{sf::Vector2u{DisplayWidth, DisplayHeight}};
    for (unsigned int y = 0; y < DisplayHeight; y++) {
        for (unsigned int x = 0; x < DisplayWidth; x++) {
            displayImage.setPixel(sf::Vector2u{x, y}, displayData[y][x] ? PixelOnColor : PixelOffColor);
        }
    }
    return sf::Texture{displayImage};
};
