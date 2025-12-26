#include "DisplayWindow.h"

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
    window.display();
}

DisplayWindow::DisplayWindow() {
    window.setFramerateLimit(RefreshRate);
}
