

/** @author @TigerNav */

#ifndef ENGINE_H_
#define ENGINE_H_


//////////////////
// Files needed
/////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Window.hpp"

/**
   @brief 
   Methods and varible that helps with the 
   entire project in different scenerios.
   
 */
class engine {

public:

/**
   @brief 
   
   Handles Mouse collision with TEXT ONLY 
   (DO NOT USE THIS METHOD FOR NORMAL COLLISION BECAUSE IT WONT WORK)
  
   @param square Text to be collided with 
  
   @return True or false depending if the mosue collided with the text
  
 */
inline static bool MouseCollision(sf::Text square);


inline static float centerOfRect(sf::FloatRect rect);

/**
   @brief 
   Font used for general text
   Define in Menu.cpp
 */
inline static sf::Font font;

};

#endif