#include <iostream>
#include <SFML/Graphics.hpp>
#include "globals/Window.cpp"
#include "Menu/Menu.cpp"
#include "globals/engine.cpp"
#include "Window.hpp"
#include "globals/TextBox.cpp"
#include "Menu/LocalMenu.cpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(1300, 800), "pong");
    Window windows(window);

    windows.~Window();
    return 0;
}