#pragma once
#include <SFML/Graphics.hpp>
#include <engine.hpp>

class LocalMenu {


private:
    sf::Text Host;
    sf::Text Join;
inline static sf::Text Title;
    sf::RenderWindow *w;
    int MenuSelection;
    bool renderLocalMenu;
public:
    LocalMenu();
    LocalMenu(sf::RenderWindow *window);
void update();
void render();

};