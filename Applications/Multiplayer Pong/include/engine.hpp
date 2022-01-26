
#ifndef ENGINE_H_
#define ENGINE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Window.hpp"

class engine {

public:

inline static bool MouseCollision(sf::Text square);
inline static float centerOfRect(sf::FloatRect rect);
inline static sf::Font font;

};

#endif