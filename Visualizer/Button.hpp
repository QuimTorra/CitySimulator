#ifndef CL_BUTTON
#define CL_BUTTON

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum button_states
{
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_ACTIVE
};

class Button
{
private:
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

    sf::Color idle;
    sf::Color hover;
    sf::Color active;

public:
    Button();
    ~Button();

    void init(float x, float y, float width, float height, std::string text);

    // Accessors
    const bool isPressed() const;

    // Functions
    void update(const sf::Vector2<int> mousePos);

    void setText(const std::string &Text, const int &fontSize);

    void draw(sf::RenderWindow *window);
};

#endif