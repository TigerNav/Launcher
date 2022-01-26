#pragma once
#include <SFML/Graphics.hpp>
#include <engine.hpp>

class LocalMenu {


private:
    sf::Text Host;
    sf::Text Join;
    sf::RenderWindow *w;
    int MenuSelection;

public:
    LocalMenu();
    LocalMenu(sf::RenderWindow *window);
void update();
void render();

};