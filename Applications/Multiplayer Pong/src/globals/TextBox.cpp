#include "TextBox.hpp"

TextBox::TextBox(){}

TextBox::TextBox(sf::RenderWindow *window) {
    w = window;
    texture.loadFromFile("/home/navin/Desktop/Programming shit i did/Launcher/Applications/Multiplayer Pong/src/Assets/TextBox.png");
    sprite.setTexture(texture);

    character = 0;
    text.setCharacterSize(15);
    text.setFont(engine::font);

}

void TextBox::InitTextBox(float x, float y) {
    sprite.setPosition(x, y);
    text.setPosition(x + 25, y + 25);
    text.setLetterSpacing(0.9);
    
}


void TextBox::update(std::string string) {
    std::string bruh;
    
    if(clock.getElapsedTime().asSeconds() > 0.01 && character < string.length()){
        clock.restart();
        character++;

        bruh = string.substr(0, character);

        text.setString(bruh);
    }
    
}

void TextBox::render() {
    w->draw(sprite);
    w->draw(text);
}