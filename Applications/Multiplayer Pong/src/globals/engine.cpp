#include "engine.hpp"




bool engine::MouseCollision(sf::Text square) {
    
    return Window::MousePosX >= square.getPosition().x 
    && Window::MousePosX <= (square.getPosition().x + square.getGlobalBounds().width) 
    && Window::MousePosY >= square.getPosition().y 
    && Window::MousePosY <= (square.getPosition().y + square.getGlobalBounds().height);

}