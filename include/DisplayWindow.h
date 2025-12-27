#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "DisplayData.h"

class DisplayWindow {
public:

    static constexpr unsigned int EmulationResolutionMultiplier = 10;
    static constexpr unsigned int RefreshRate = 60;
private:
    sf::RenderWindow window{sf::VideoMode(
            {
                    DisplayData::DisplayWidth * EmulationResolutionMultiplier,
                    DisplayData::DisplayHeight * EmulationResolutionMultiplier
            }), "CHIP-8"};
public:
    DisplayWindow();

    bool ShouldBeOpen() const;

    void PollEvents();

    void Draw();

private:
    void HandleEvent(const sf::Event &event);
};
