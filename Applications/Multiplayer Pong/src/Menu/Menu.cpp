#include "Menu/Menu.hpp"

Menu::Menu() {

}

Menu::Menu(sf::RenderWindow *window) : textbox(window), 
                                       localMenu(window) { 
    w = window;

    showMenu = true;

    engine::font.loadFromFile("/home/navin/Desktop/Programming shit i did/Launcher/Applications/Multiplayer Pong/src/Assets/shit.ttf");
    MenuSelection = 1;

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

    textbox.InitTextBox(420, 620);

}

void Menu::PollUpdate() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        MenuSelection--;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        MenuSelection++;

}

void Menu::update() {

    if(showMenu){

        if(engine::MouseCollision(LocalGame)) {
            MenuSelection = 1;
        }
        else if(engine::MouseCollision(OnlineMatch)) {
            MenuSelection = 2;
        }
        else if(engine::MouseCollision(Option)) {
            MenuSelection = 3;
        }
        else if(engine::MouseCollision(exit)) {
            MenuSelection = 4;
        }
        else{
            MenuSelection = -1;
            textbox.character = 0;
            textbox.update(" ");
            LocalGame.setFillColor(sf::Color::White);
            OnlineMatch.setFillColor(sf::Color::White);
            Option.setFillColor(sf::Color::White);
            exit.setFillColor(sf::Color::White);
        }
            
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
            LocalGame.setFillColor(sf::Color::Cyan);
            OnlineMatch.setFillColor(sf::Color::White);
            Option.setFillColor(sf::Color::White);
            exit.setFillColor(sf::Color::White);
            textbox.update("Play a game within your local \nnetwork. Or Host a game for \neveryone in your local \nnetwork join");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                showLocal = true;
                showMenu = false;
                
            }
            break;
        case 2:
            if(changeOnline){
                textbox.character = 0;
                changeLocal = true;
                changeOnline = false;
                changeOption = true;
                changeExit = true;
                }
            LocalGame.setFillColor(sf::Color::White);
            OnlineMatch.setFillColor(sf::Color::Cyan);
            Option.setFillColor(sf::Color::White);
            exit.setFillColor(sf::Color::White);
            textbox.update("Find a match with a another \nrandom person waiting to be \nchallanged.");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                showOnline = true;
                showMenu = false;
            }
            break;
        case 3:
            if(changeOption){
                textbox.character = 0;
                changeLocal = true;
                changeOnline = true;
                changeOption = false;
                changeExit = true;
                } 
            LocalGame.setFillColor(sf::Color::White);
            OnlineMatch.setFillColor(sf::Color::White);
            Option.setFillColor(sf::Color::Cyan);
            exit.setFillColor(sf::Color::White);
            textbox.update("Optimize the game experience \nto your liking.");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                showOption = true;
                showMenu = false;
            }
            break;
        case 4:
            if(changeExit){
                textbox.character = 0;
                changeLocal = true;
                changeOnline = true;
                changeOption = true;
                changeExit = false;
                }
            LocalGame.setFillColor(sf::Color::White);
            OnlineMatch.setFillColor(sf::Color::White);
            Option.setFillColor(sf::Color::White);
            exit.setFillColor(sf::Color::Cyan);
            textbox.update("Sometimes playing a game too \nmuch makes you worse. Go take \na break and come back when \nyou feel better!");
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                showExit = true;
                showMenu = false;
            }
            break;
        case 5:
            MenuSelection = 1;
            break;
        };

    }

    if(showLocal){
        localMenu.update();
    }
    if(showOption){

    }
    if(showExit){
        
        std::exit(0);
    }

}

void Menu::render() {

    if(showMenu){
        w->draw(Title);
        w->draw(LocalGame);
        w->draw(OnlineMatch);
        w->draw(Option);
        w->draw(exit);
        textbox.render();
    }
    if(showLocal){
        localMenu.render();
    }

}

Menu::~Menu() {
    
}