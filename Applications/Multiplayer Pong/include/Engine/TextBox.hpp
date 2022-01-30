#pragma once
#include <SFML/Graphics.hpp>
#include "engine.hpp"
class TextBox{

private:
    sf::RenderWindow *w;
inline static sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
    sf::Clock clock;
    
public:
    unsigned int character;
    TextBox();
    TextBox(sf::RenderWindow *window);
void InitTextBox(float x, float y);
void update(std::string string);
void render();


};