
/** @author @TigerNav */


//////////////////
// Files needed
/////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "Menu/Menu.hpp"


/**
   @brief 
  
   Handles Window stuff
  
 */
class Window {

public:

/** 
    @brief 

    Varible to get mouses X 
    position while in window

 */
inline static float MousePosX;


/** 
    @brief 

    Varible to get mouses Y 
    position while in window 

*/
inline static float MousePosY;

/** Initilize Menu */
Menu menu;


/** 
 
    @brief 
    Window contructor that intializes the menu, sets window position and starts the update method

    @param window 
    reference pointer used to handle window and pass on to other methods. Defined at main.cpp

 */
Window(sf::RenderWindow &window);

/**
 
   @brief 
   Runs every frame. Handles all of the input and rendering.
   
   @param window reference pointer used for other parameters that need window variable. Defined in Window()

 */
void update(sf::RenderWindow &window);

// Window decontructor
~Window();

};