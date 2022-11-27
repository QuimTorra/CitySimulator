#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include "../Domain/Agent.hpp"

class AgentManager
{
private:
    std::unordered_map<int, std::pair<sf::RectangleShape, Agent>> cars;
    City *city;

public:
    AgentManager();
    AgentManager(City &city);
    ~AgentManager();

    int get_num_cars();

    void newCar(Node &start, const int &speed);

    void deleteCar();

    float try_move(const int i, sf::Vector2f pos, float movedDistance);

    void update();

    void draw(sf::RenderWindow *window);
};