#pragma once
#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"

class LocalMenu {


private:
inline static sf::Text Title;
    sf::Text Host;
    sf::Text Join;
    sf::Text Back;
    sf::RenderWindow *w;
    int MenuSelection;
    bool renderLocalMenu;
    bool localMenuhost = false, localMenujoin = false;
public:
    LocalMenu();
    LocalMenu(sf::RenderWindow *window);
void update();
void render();

};