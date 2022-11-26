#include "Button.hpp"
#include <iostream>

// https://www.youtube.com/watch?v=xtBNgDncRnU  min 9
// https://www.youtube.com/watch?v=HjkWqCa7Ktw

Button::Button() {}

Button::~Button() {}

void Button::init(float x, float y, float width, float height, std::string text)
{
    this->buttonState = BTN_IDLE;
    this->idle = sf::Color{118, 118, 118, 255};
    this->hover = sf::Color{98, 98, 98, 255};
    this->active = sf::Color{78, 78, 78, 255};
    this->font.loadFromFile("Montserrat-Bold.ttf");

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setOrigin(sf::Vector2f(width / 2, height / 2));
    this->shape.setOutlineColor(sf::Color{15, 15, 15, 255});
    this->shape.setOutlineThickness(2.f);
    this->shape.setFillColor(this->idle);

    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color(15, 15, 15, 255));
    this->text.setCharacterSize(17);
    this->text.setOrigin(this->text.getGlobalBounds().width / 2.f, this->text.getGlobalBounds().height / 2.f);
    this->text.setPosition(sf::Vector2f(x, y));
}

// Acces
const bool Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
    {
        return true;
    }
    return false;
}
// Function
void Button::update(const sf::Vector2<int> mousePos)
{
    // idle
    this->buttonState = BTN_IDLE;

    // hover
    if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y)))
    {
        this->buttonState = BTN_HOVER;

        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idle);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hover);

        break;
    case BTN_ACTIVE:
        this->shape.setFillColor(this->active);

        break;
    default:
        this->shape.setFillColor(sf::Color::Red);
        break;
    }
}

void Button::draw(sf::RenderWindow *window)
{
    window->draw(this->shape);
    window->draw(this->text);
}
