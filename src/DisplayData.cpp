#include "DisplayData.h"
#include "SFML/Graphics/Image.hpp"

bool DisplayData::Draw(const std::vector<uint8_t>& spriteData,
                       uint8_t xPos,
                       uint8_t yPos)
{
    bool collisionHappened = false;

    for (size_t row = 0; row < spriteData.size(); row++) {
        if (yPos + row >= DisplayHeight) continue;

        uint8_t spriteByte = spriteData[row];

        for (int col = 0; col < 8; col++) {
            if (xPos + col >= DisplayWidth) continue;

            bool spriteBit = spriteByte & (0x80 >> col);
            if (!spriteBit) continue;

            if (displayData[yPos + row][xPos + col]) {
                collisionHappened = true;
            }

            displayData[yPos + row][xPos + col] = !displayData[yPos + row][xPos + col];
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
