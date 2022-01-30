#include "Menu/LocalMenu.hpp"

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

    Back.setFont(engine::font);
    Back.setString("Back");
    Back.setCharacterSize(30);
    Back.setPosition(0, w->getSize().y - 30);


    renderLocalMenu = true;

}

void LocalMenu::update() {

    if(renderLocalMenu) {

        if(engine::MouseCollision(Host))
            MenuSelection = 1;
        if(engine::MouseCollision(Join))
            MenuSelection = 2;
        if(engine::MouseCollision(Back)){
            MenuSelection = 3;
        }
        else{
            MenuSelection = -1;
            Host.setFillColor(sf::Color::White);
            Join.setFillColor(sf::Color::White);
            Back.setFillColor(sf::Color::White);
        }
        

        switch(MenuSelection) {
            case 1:
                Host.setFillColor(sf::Color::Cyan);
                Join.setFillColor(sf::Color::White);
                Back.setFillColor(sf::Color::White);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

                    renderLocalMenu = false;
                }
                break;
            case 2:
                Host.setFillColor(sf::Color::White);
                Join.setFillColor(sf::Color::Cyan);
                Back.setFillColor(sf::Color::White);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){

                    renderLocalMenu = false;
                }
                break;
            case 3:
                Host.setFillColor(sf::Color::White);
                Join.setFillColor(sf::Color::White);
                Back.setFillColor(sf::Color::Cyan);
        }

}

}

void LocalMenu::render() {

    if(renderLocalMenu) {
        w->draw(Title);
        w->draw(Host);
        w->draw(Join);
        w->draw(Back);
    }

}