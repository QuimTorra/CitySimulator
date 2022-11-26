#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Menu
{
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

public:
    Menu();
    ~Menu();

    void init();
    void draw(sf::RenderWindow *window);
};
