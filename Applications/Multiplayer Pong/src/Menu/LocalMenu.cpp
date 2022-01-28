#include "LocalMenu.hpp"

LocalMenu::LocalMenu(){}

LocalMenu::LocalMenu(sf::RenderWindow *window){
    w = window;

    Host.setFont(engine::font);
    Host.setString("Host a Local game");
    Host.setCharacterSize(20);
    Host.setPosition(490, 300);

    Join.setFont(engine::font);
    Join.setString("Join a Local game");
    Join.setCharacterSize(20);
    Join.setPosition(490, 500);

    Title.setFont(engine::font);
    Title.setString("Local Game");
    Title.setCharacterSize(30);
    Title.setPosition(510, 100);

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
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                
            }
            break;
        case 2:
            Host.setFillColor(sf::Color::White);
            Join.setFillColor(sf::Color::Cyan);
            break;
    }

}

void LocalMenu::render() {

    if(renderLocalMenu) {
        w->draw(Title);
        w->draw(Host);
        w->draw(Join);
    }

}