#include "LocalMenu.hpp"

LocalMenu::LocalMenu(){}

LocalMenu::LocalMenu(sf::RenderWindow *window){
    w = window;

    Host.setFont(engine::font);
    Host.setString("Host a Local game");
    Host.setCharacterSize(20);
    Host.setPosition(450, 200);

    Join.setFont(engine::font);
    Join.setString("Join a Local game");
    Join.setCharacterSize(20);
    Join.setPosition(450, 400);



}

void LocalMenu::update() {

    if(engine::MouseCollision(Host))
        MenuSelection = 1;
    if(engine::MouseCollision(Join))
        MenuSelection = 2;

    switch(MenuSelection) {
        case 1:
            Host.setFillColor(sf::Color::Cyan);
            Join.setFillColor(sf::Color::White);
            break;
        case 2:
            Host.setFillColor(sf::Color::White);
            Join.setFillColor(sf::Color::Cyan);
            break;
    }

}

void LocalMenu::render() {

    w->draw(Host);
    w->draw(Join);

}