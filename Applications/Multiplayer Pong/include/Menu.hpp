#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "engine.hpp"
#include "TextBox.hpp"

class Menu {

private:
    sf::Text Title, LocalGame, OnlineMatch, Option, exit;
    std::vector<sf::Text> MenuItems;
    sf::RenderWindow *w;
    TextBox textbox;
    int MenuSelection;
    bool changeLocal = true, changeOnline = true, changeOption = true, changeExit = true;

public:
    Menu();
    Menu(sf::RenderWindow *window);

void PollUpdate();
void update();
void render();
    ~Menu();

};