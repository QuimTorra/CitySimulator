#include "AgentManager.hpp"
#include "../Domain/Agent.hpp"

AgentManager::AgentManager(){};
AgentManager::~AgentManager(){};

void AgentManager::newCar(Node start, const int &speed)
{
    Agent carAgent = Agent(start, speed);
    sf::RectangleShape car;
    car.setPosition(sf::Vector2f(start.get_pos().first, start.get_pos().second));
    car.setSize(sf::Vector2f(18.f, 40.f));
    car.setOrigin(sf::Vector2f(9.f, 20.f));
    car.setOutlineColor(sf::Color{150, 0, 0, 255});
    car.setOutlineThickness(2.f);
    car.setFillColor(sf::Color{255, 0, 0, 255});

    std::pair<sf::RectangleShape, Agent> aux;
    aux.first = car;
    aux.second = carAgent;
    cars.push_back(aux);
    std::cout << "newCar" << std::endl;
};

void AgentManager::deleteCar()
{
    if (cars.size() > 0)
        cars.pop_back();
};

void AgentManager::update()
{
    int size = cars.size();
    std::list<std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    std::cout << "start loop" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        Agent &carAgent = (*it).second;
        std::cout << "11111111111111111111" << std::endl;

        carAgent.tick();
        std::cout << "&&&&&&&&&&" << std::endl;
        float angle = carAgent.get_angle();
        int speed = carAgent.get_speed();

        sf::RectangleShape &carShape = (*it).first;

        float radians = 3.1415926536 / 180 * angle;
        float x = float(speed) * sin(radians);
        float y = float(speed) * -cos(radians);
        carShape.move(-x, -y);
        carShape.setRotation(angle);
    }
};

void AgentManager::draw(sf::RenderWindow *window)
{
    std::cout << "drawCar" << std::endl;
    int size = cars.size();
    std::list<std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    for (int i = 0; i < size; ++i)
    {
        window->draw((*it).first);
    }
    std::cout << "enddrawCar" << std::endl;
}