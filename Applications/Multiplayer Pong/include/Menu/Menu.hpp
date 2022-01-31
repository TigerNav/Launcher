
/** @author @TigerNav */


//////////////////
// Files needed
/////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Engine/engine.hpp"
#include "Engine/TextBox.hpp"
#include "LocalMenu.hpp"


/**
   @brief 
    
    Menu Handler. Branches out to other 
    submenus using booleans for rendering 
    and updating.
  
 */
class Menu {

private:

    /** Menu Item. Depending on the name thats what it. */
    sf::Text Title, LocalGame, OnlineMatch, Option, exit;

    /** Window that we will use for the entire class. */
    sf::RenderWindow *w;

    /** Instance of the text box at the bottom. Found in Textbox.hpp. */
    TextBox textbox;

    /** Menu selection int for logic. */
    int MenuSelection;

    /** Booleans used to change characters in the text box. */ 
    bool changeLocal = true, changeOnline = true, changeOption = true, changeExit = true;

    /** Booleans to show if the whichever state is visible or not. Depending on the name. */
    bool showMenu, showLocal, showOnline, showOption, showExit;

    /** Instance with you click "Local Game" item. */
    LocalMenu localMenu;

public:

/**
   @brief 
    
    Default Contructor. Literally does nothing.
  
 */
    Menu();
/**
   @brief 
    
    Contructor that initilizes all of the everything 
    used include ones from external files.
  
   @param window turns into a public variable that will be used for drawing on screen.

 */
    Menu(sf::RenderWindow *window);


/**
   @brief 
    
    Updates in poll event method.

  */
void PollUpdate();

/**
   @brief 
    
    Updates every frame without rendering.

  */
void update();
/**
   @brief 
    
    Renders everything used in the class. Handles the switch between everything thats has to be handled.

  */
void render();
/**
   @brief Destroy the Menu object
  
  
 */
~Menu();

};