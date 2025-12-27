#include <iostream>
#include "DisplayWindow.h"
#include "SFML/Graphics/Sprite.hpp"

DisplayWindow::DisplayWindow(const DisplayData &displayData) : displayData(displayData) {
    window.setFramerateLimit(RefreshRate);
}

bool DisplayWindow::ShouldBeOpen() const {
    return window.isOpen();
}

void DisplayWindow::PollEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        HandleEvent(event.value());
    }
}

void DisplayWindow::HandleEvent(const sf::Event &event) {
    if (event.is<sf::Event::Closed>()) {
        window.close();
    }
}

void DisplayWindow::Draw() {
    window.clear();
    sf::Texture texture = displayData.GetDisplayTexture();
    sf::Sprite sprite{texture};
    sprite.setScale(sf::Vector2f{EmulationResolutionMultiplier, EmulationResolutionMultiplier});
    window.draw(sprite);
    window.display();
}