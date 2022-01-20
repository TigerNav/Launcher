#include "Window.hpp"

Window::Window(sf::RenderWindow &window) {

    menu = Menu(&window);
    update(window);

}


void Window::update(sf::RenderWindow &window) {


    while(window.isOpen()){

        MousePosX = sf::Mouse::getPosition(window).x;
        MousePosY = sf::Mouse::getPosition(window).y;

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
                
            menu.PollUpdate();
        }
        menu.update();
        

        window.clear(sf::Color(41, 41, 41));

        menu.render();
    
        window.display();
    }
}

Window::~Window() {

}
