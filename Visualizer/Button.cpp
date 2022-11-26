#include "Button.hpp"

//https://www.youtube.com/watch?v=xtBNgDncRnU
//https://www.youtube.com/watch?v=HjkWqCa7Ktw

Button::Button(const pair<Int,Int>& size, const pair<Int,Int>& pos) {
    this->shape.setSize(size.first.f, size.second.f);
    this->shape.setPosition(pos.first.f, pos.second.f);
    this->shape.setOrigin(sf::Vector2f(size.first.f, size.second.f)/2.f);
    this->shape.setFillColor(this->idle);
    this->shape.setOutlineColor(sf::Color{50, 50, 50, 255});
    this->shape.setOutlineThickness(2.f);
    
}

Button::~Button();

void Button::setText(const String& Text, const Integer& fontSize) {
    this->text.setString(Text);
    this->text.setCharacterSize(fontSize);
    this->text.setOrigin(sf::Vector2f(this->text.getLocalBounds.x, this->text.getLocalBounds.y));
    this->text.setPosition(this->shape.getPosition);
}

void Button::draw(sf::RenderWindow window) {
    window.draw(shape);
    window.draw(text);
}