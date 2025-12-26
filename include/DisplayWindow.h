#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

class DisplayWindow {
public:
    static constexpr unsigned int DisplayWidth = 64;
    static constexpr unsigned int DisplayHeight = 64;
    static constexpr unsigned int EmulationResolutionMultiplier = 10;
    static constexpr unsigned int RefreshRate = 60;
private:
    sf::RenderWindow window{sf::VideoMode({640, 320}), "CHIP-8"};
public:
    DisplayWindow();

    bool ShouldBeOpen() const;

    void PollEvents();

    void Draw();

private:
    void HandleEvent(const sf::Event &event);
};
