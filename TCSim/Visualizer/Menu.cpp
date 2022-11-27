#include "Menu.hpp"

Menu::Menu(){};
Menu::~Menu(){};

void Menu::init()
{
    this->font.loadFromFile("Montserrat-Bold.ttf");

    this->shape.setSize(sf::Vector2f(350.f, 200.f));
    this->shape.setPosition(750.f, 0.f);
    this->shape.setOutlineColor(sf::Color{15, 15, 15, 255});
    this->shape.setOutlineThickness(1.f);
    this->shape.setFillColor(sf::Color{138, 138, 138, 255});

    this->text.setFont(this->font);
    this->text.setStyle(sf::Text::Underlined);
    this->text.setString("Traffic Simulator");
    this->text.setFillColor(sf::Color(15, 15, 15, 255));
    this->text.setCharacterSize(27);
    this->text.setOrigin(this->text.getGlobalBounds().width / 2.f, this->text.getGlobalBounds().height / 2.f);
    this->text.setPosition(this->shape.getPosition().x + 165.f, 20.f);
};
void Menu::draw(sf::RenderWindow *window)
{
    window->draw(this->shape);
    window->draw(this->text);
}
