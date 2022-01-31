
/** @author @TigerNav */


//////////////////
// Files needed
/////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include "engine.hpp"


/**
   @brief 
   
   Create a text box that can be used to display text in a typewriter format
   
 */
class TextBox{

private:
    sf::RenderWindow *w;
inline static sf::Texture texture;
    sf::Sprite sprite;
    sf::Text text;
    sf::Clock clock;

    
public:
    unsigned int character;
/**
   @brief Default contructor. Literally does nothing
   
 */
    TextBox();
/**
   @brief Construct a new Text Box object
   
   @param window so you can draw in later methods
 */
    TextBox(sf::RenderWindow *window);
/**
   @brief Initilization for position 
   
   @param x for the x position
   @param y for the y position
 */
void InitTextBox(float x, float y);
/**
   @brief logic for the typewriting effect. Cant explain since very complicated gamer
   
   @param string the string for text
 */
void update(std::string string);

/**
 * @brief call this method when you want to render the textbox
 * 
 */
void render();


};