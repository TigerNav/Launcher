#include "Window.hpp"

Window::Window(sf::RenderWindow &window) {

    menu = Menu(&window);
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - window.getSize().x / 2, 
                                    (sf::VideoMode::getDesktopMode().height / 2) - window.getSize().y / 2));
                                    
    update(window);

}


void Window::update(sf::RenderWindow &window) {


    while(window.isOpen()){

        MousePosX = sf::Mouse::getPosition(window).x;
        MousePosY = sf::Mouse::getPosition(window).y;

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                exit(0);
            }
                
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
