#include "DisplayData.h"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Color.hpp"
#include "EmulationSettings.h"

DisplayData::DisplayData(const EmulationSettings &emulationSettings) : emulationSettings(emulationSettings) {};

bool DisplayData::Draw(const std::vector<uint8_t> &spriteData,
                       uint8_t xPos,
                       uint8_t yPos) {
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
            sf::Color colorToDraw;

            if (displayData[y][x]) {
                colorToDraw = sf::Color(
                        static_cast<unsigned char>(emulationSettings.PixelColor[0] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.PixelColor[1] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.PixelColor[2] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.PixelColor[3] * 255.0f)
                );
            } else {
                colorToDraw = sf::Color(
                        static_cast<unsigned char>(emulationSettings.BackgroundColor[0] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.BackgroundColor[1] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.BackgroundColor[2] * 255.0f),
                        static_cast<unsigned char>(emulationSettings.BackgroundColor[3] * 255.0f)
                );
            }

            displayImage.setPixel(sf::Vector2u{x, y}, colorToDraw);
        }
    }

    sf::Texture texture;
    texture.loadFromImage(displayImage);
    return texture;
}
