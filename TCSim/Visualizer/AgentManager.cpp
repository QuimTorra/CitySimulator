#define _USE_MATH_DEFINES
#include "AgentManager.hpp"
#include "../Domain/Agent.hpp"

AgentManager::AgentManager(){};

AgentManager::AgentManager(City &city)
{
    this->city = &city;
};

AgentManager::~AgentManager(){};

int AgentManager::get_num_cars() {
    return this->cars.size();
}

void AgentManager::newCar(Node &start, const int &speed)
{
    Agent carAgent = Agent(start, speed, city);
    sf::RectangleShape car;
    car.setPosition(sf::Vector2f(start.get_pos().first, start.get_pos().second));
    car.setSize(sf::Vector2f(18.f, 40.f));
    car.setOrigin(sf::Vector2f(9.f, 20.f));
    car.setOutlineThickness(2.f);

    // RANDOM COLOUR
    sf::Uint8 randR = rand() % 178, randG = rand() % 178, randB = rand() % 178;
    sf::Uint8 randROut = (randR + 50), randGOut = (randG + 50), randBOut = (randB + 50);
    car.setOutlineColor(sf::Color{randR, randG, randB, 255});
    car.setFillColor(sf::Color{randROut, randGOut, randBOut, 255});

    std::pair<sf::RectangleShape, Agent> aux;
    aux.first = car;
    aux.second = carAgent;
    cars.push_back(aux);
};

void AgentManager::deleteCar()
{
    if (cars.size() > 0)
        cars.pop_back();
};

void AgentManager::update()
{
    std::list<std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    while (it != cars.end())
    {
        Agent &carAgent = (*it).second;

        carAgent.tick();
        float angle = carAgent.get_angle();
        float movedDistance = carAgent.get_movingDistance();

        sf::RectangleShape &carShape = (*it).first;

        float radians = M_PI / 180 * angle;
        float x = movedDistance * sin(radians);
        float y = movedDistance * -cos(radians);

        carShape.move(-x, -y);
        carShape.setRotation(angle);
        it++;
    }
};

void AgentManager::draw(sf::RenderWindow *window)
{
    std::list<std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    while (it != cars.end())
    {
        window->draw((*it).first);
        it++;
    }
}