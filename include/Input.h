#pragma once

#include <array>
#include <SFML/Window.hpp>

/*
 * We're mapping this chip-8 layout to
 * qwerty keyboard
    1 2	3 C
    4 5	6 D
    7 8 9 E
    A 0	B F
    =>
    1 2 3 4
    q w e r
    a s d f
    z x c v
 */

class Input {
public:

    static constexpr std::array<sf::Keyboard::Key, 16> ValueToKey{
            sf::Keyboard::Key::X,
            sf::Keyboard::Key::Num1,
            sf::Keyboard::Key::Num2,
            sf::Keyboard::Key::Num3,
            sf::Keyboard::Key::Q,
            sf::Keyboard::Key::W,
            sf::Keyboard::Key::E,
            sf::Keyboard::Key::A,
            sf::Keyboard::Key::S,
            sf::Keyboard::Key::D,
            sf::Keyboard::Key::Z,
            sf::Keyboard::Key::C,
            sf::Keyboard::Key::Num4,
            sf::Keyboard::Key::R,
            sf::Keyboard::Key::F,
            sf::Keyboard::Key::V
    };
};
