
// Author @TigerNav //

#include <iostream>
#include <SFML/Graphics.hpp>
#include "globals/Window.cpp"
#include "Menu/Menu.cpp"
#include "globals/engine.cpp"
#include "Window.hpp"
#include "globals/TextBox.cpp"
#include "Menu/LocalGameMenu/LocalMenu.cpp"


// Entry point for project (DO NOT EDIT UNLESS NECESSARY)
int main() {
    sf::RenderWindow window(sf::VideoMode(1300, 800), "pong");
    Window windows(window);

    windows.~Window();
    return 0;
}