#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Engine/engine.hpp"
#include "Engine/TextBox.hpp"
#include "LocalMenu.hpp"

class Menu {

private:
    sf::Text Title, LocalGame, OnlineMatch, Option, exit;
    std::vector<sf::Text> MenuItems;
    sf::RenderWindow *w;
    TextBox textbox;
    int MenuSelection;
    bool changeLocal = true, changeOnline = true, changeOption = true, changeExit = true;
    bool showMenu, showLocal, showOnline, showOption, showExit;
    LocalMenu localMenu;

public:
    Menu();
    Menu(sf::RenderWindow *window);

void PollUpdate();
void update();
void render();
    ~Menu();

};