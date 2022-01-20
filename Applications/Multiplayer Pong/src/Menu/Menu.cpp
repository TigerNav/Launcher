#include "Menu.hpp"

Menu::Menu() {

}

Menu::Menu(sf::RenderWindow *window) : textbox(window){
w = window;

engine::font.loadFromFile("/home/navin/Desktop/Programming shit i did/The Sethi Applications/Applications/Multiplayer Pong/src/Assets/shit.ttf");


Title.setFont(engine::font);
Title.setString("Multiplayer Pong");
Title.setCharacterSize(35);
Title.setPosition(380, 50);

LocalGame.setFont(engine::font);
LocalGame.setString("Local Game");
LocalGame.setCharacterSize(20);
LocalGame.setPosition(550, 200);

OnlineMatch.setFont(engine::font);
OnlineMatch.setString("Online Match");
OnlineMatch.setCharacterSize(20);
OnlineMatch.setPosition(530, 300);

Option.setFont(engine::font);
Option.setString("Options");
Option.setCharacterSize(20);
Option.setPosition(580,400);

exit.setFont(engine::font);
exit.setString("Exit");
exit.setCharacterSize(20);
exit.setPosition(610, 500);

MenuItems.push_back(Title);
MenuItems.push_back(LocalGame);
MenuItems.push_back(OnlineMatch);
MenuItems.push_back(Option);
MenuItems.push_back(exit);

textbox.InitTextBox(420, 620);

}

void Menu::PollUpdate() {

}

void Menu::update() {

    

    if(engine::MouseCollision(LocalGame))
        MenuSelection = 1;
    if(engine::MouseCollision(OnlineMatch))
        MenuSelection = 2;
    if(engine::MouseCollision(Option))
        MenuSelection = 3;
    if(engine::MouseCollision(exit))
        MenuSelection = 4;

    std::cout << MenuSelection << std::endl;

    switch (MenuSelection) {
    case 0:
        MenuSelection = 4;
        break;
    case 1:
        if(changeLocal){
            textbox.character = 0;
            changeLocal = false;
            changeOnline = true;
            changeOption = true;
            changeExit = true;
            }
        textbox.update("Play a game within your local \nnetwork. Or Host a game for \neveryone in your local \nnetwork join");
        break;
    case 2:
        if(changeOnline){
            textbox.character = 0;
            changeLocal = true;
            changeOnline = false;
            changeOption = true;
            changeExit = true;
            }
        textbox.update("Find a match with a another \nrandom person waiting to be \nchallanged.");
        break;
    case 3:
        if(changeOption){
            textbox.character = 0;
            changeLocal = true;
            changeOnline = true;
            changeOption = false;
            changeExit = true;
            } 
        textbox.update("Optimize the game experience \nto your liking.");
        break;
    case 4:
        if(changeExit){
            textbox.character = 0;
            changeLocal = true;
            changeOnline = true;
            changeOption = true;
            changeExit = false;
            }
        textbox.update("Sometimes playing a game too \nmuch makes you worse. Go take \na break and come back when \nyou feel better!");
        break;
    case 5:
        MenuSelection = 1;
        break;
    };

    
}

void Menu::render() {
    w->draw(Title);
    w->draw(LocalGame);
    w->draw(OnlineMatch);
    w->draw(Option);
    w->draw(exit);
    textbox.render();
    

}

Menu::~Menu() {
    
}