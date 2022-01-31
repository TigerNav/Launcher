
/** @author @TigerNav */


//////////////////
// Files needed
/////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include "Engine/engine.hpp"

class LocalMenu
{

private:
    inline static sf::Text Title;
    sf::Text Host;
    sf::Text Join;
    sf::Text Back;
    sf::RenderWindow *w;
    int MenuSelection;
    bool renderLocalMenu;
    bool localMenuhost = false, localMenujoin = false;

public:
    /**
       @brief Defualt Contructor. Literally does nothing

     */
    LocalMenu();
    /**
     * @brief Construct a new Local Menu object
     *
     * @param window for the render method and used for other stuff
     */
    LocalMenu(sf::RenderWindow *window);

    /**
     * @brief runs every frame like every other update method
     *
     */
    void update();
    /**
     * @brief renders the stuff on the windows like every other
     *
     */
    void render();
};