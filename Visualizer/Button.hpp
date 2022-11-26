#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    const sf::Color& idle = sf::Color{118, 118, 118, 255};
    const sf::Color& hover = sf::Color{138, 138, 138, 255};
    const sf::Color& active = sf::Color{158, 158, 158, 255};

public:
    Button(const pair<Int,Int>& size, const pair<Int,Int>& pos);
    ~Button();

    void setText(const String& Text, const Integer& fontSize);

    void draw(sf::RenderWindow window);

}