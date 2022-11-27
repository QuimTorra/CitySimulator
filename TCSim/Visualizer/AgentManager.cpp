#include "AgentManager.hpp"
#include "../Domain/Agent.hpp"

AgentManager::AgentManager(){};

AgentManager::AgentManager(City &city)
{
    this->city = &city;
};

AgentManager::~AgentManager(){};

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
    this->cars.insert(make_pair(cars.size(), aux));
};

void AgentManager::deleteCar()
{
    if (cars.size() > 0)
        cars.erase(cars.size() - 1);
};

float AgentManager::try_move(const int i, sf::Vector2f pos, float movedDistance)
{
    float distance = movedDistance;
    std::unordered_map<int, std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    int j = 0;
    while (distance > 0 and it != cars.end())
    {
        if (i != j)
        {
            sf::Vector2f pos2 = it->second.first.getPosition();
            float m1 = (pos.x - pos2.x);
            float m2 = (pos.x - pos2.y);

            float length(sqrt(m1 * m1 + m2 * m2));
            if (length - 50.f < distance)
                distance = length - 50.f;
        }
        it++;
        j++;
    }
    if (distance <= 0)
        return 0;
    else
        return distance;
}

void AgentManager::update()
{
    int size = cars.size();
    std::unordered_map<int, std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    for (int i = 0; i < size; ++i)
    {
        Agent &carAgent = (*it).second.second;
        sf::RectangleShape &carShape = (*it).second.first;

        // get min speed
        float movedDistance = carAgent.get_movingDistance();

        // get best possible movement
        movedDistance = try_move(i, carShape.getPosition(), movedDistance);
        if (movedDistance != 0)
        {
            float angle = carAgent.get_angle();

            float radians = M_PI / 180 * angle;
            float x = movedDistance * sin(radians);
            float y = movedDistance * -cos(radians);

            carShape.move(-x, -y);
            carShape.setRotation(angle);
        }
        carAgent.tick(movedDistance);
        it++;
    }
};

void AgentManager::draw(sf::RenderWindow *window)
{
    std::unordered_map<int, std::pair<sf::RectangleShape, Agent>>::iterator it = cars.begin();
    while (it != cars.end())
    {
        window->draw((*it).second.first);
        it++;
    }
}