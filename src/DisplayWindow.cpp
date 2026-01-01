#include "DisplayWindow.h"
#include <SFML/Graphics/Sprite.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <iostream>

DisplayWindow::DisplayWindow(const DisplayData &displayData) : displayData(displayData) {
    if(!ImGui::SFML::Init(window)){
        std::cerr << "Could not initialize imgui\n";
    }
}

bool DisplayWindow::ShouldBeOpen() const {
    return window.isOpen();
}

void DisplayWindow::PollEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        ImGui::SFML::ProcessEvent(window, *event);
        HandleEvent(event.value());
    }
}

void DisplayWindow::HandleEvent(const sf::Event &event) {
    if (event.is<sf::Event::Closed>()) {
        window.close();
    }
}

void DisplayWindow::Draw() {
    sf::Time elapsed = clock.restart();
    ImGui::SFML::Update(window, elapsed);
    window.clear();

    sf::Texture texture = displayData.GetDisplayTexture();
    sf::Sprite sprite{texture};
    sprite.setScale(sf::Vector2f{EmulationResolutionMultiplier, EmulationResolutionMultiplier});

    window.draw(sprite);
    ImGui::SFML::Render(window);
    window.display();
}
