#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

class Window {

private:



public:

inline static float MousePosX;
inline static float MousePosY;

Menu menu;
Window(sf::RenderWindow &window);
void update(sf::RenderWindow &window);
~Window();

};