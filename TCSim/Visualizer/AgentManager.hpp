#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <list>
#include "../Domain/Agent.hpp"

class AgentManager
{
private:
    std::list<std::pair<sf::RectangleShape, Agent>> cars;

public:
    AgentManager();
    ~AgentManager();

    void newCar(Node &start, const int &speed);

    void deleteCar();

    void update();

    void draw(sf::RenderWindow *window);
};