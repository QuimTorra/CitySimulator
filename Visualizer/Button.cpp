#include "Button.hpp"

//https://www.youtube.com/watch?v=xtBNgDncRnU  min 9
//https://www.youtube.com/watch?v=HjkWqCa7Ktw

Button::Button(float x, float y, float width, float height, std::string text, sf::Color idle, sf::Color hover, sf::Color active) 
: idle(idle),hover(hover),active(active)
{
    this->buttonState = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->text.setString(text);
    this->text.setFillColor(sf::Color(70,70,70,200));
    this->text.setCharacterSize(12);
    this->text.setPosition(
        this->shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
    );
    this->shape.setFillColor(this->idle);
}

Button::~Button()
{

}
//Acces
const bool Button::isPressed() const
{
    if(this->buttonState == BTN_ACTIVE) {
        return true;
    }
    return false;
}
//Function
void Button::update(const sf::Vector2f mousePos)
{
    //idle
    this->buttonState = BTN_IDLE;

    //hover

    if (this->shape.getGlobalBounds().contains(mousePos)) 
    {
        this->buttonState = BTN_HOVER;

        //Pressed
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

void Button::render(sf::RenderTarget * target) 
{
    target->draw(this->shape);
}



