#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "DisplayData.h"
#include "SFML/Graphics/Sprite.hpp"

class EmulationSettings;

class UserInterface;

class DisplayWindow {
public:
    static constexpr unsigned int EmulationResolutionMultiplier = 10;
private:
    const DisplayData &displayData;
    UserInterface &userInterface;
    sf::Clock clock;

    sf::RenderWindow window{sf::VideoMode(
            {
                    DisplayData::DisplayWidth * EmulationResolutionMultiplier,
                    DisplayData::DisplayHeight * EmulationResolutionMultiplier,
            }), "CHIP-8", sf::Style::Titlebar | sf::Style::Close};

public:
    explicit DisplayWindow(const DisplayData &displayData, UserInterface &userInterface);

    bool ShouldBeOpen() const;

    void PollEvents();

    void Draw();

private:
    void HandleEvent(const sf::Event &event);
};
