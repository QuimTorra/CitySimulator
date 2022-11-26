#include "visualizerCity.hpp"

visualizerCity::visualizerCity(){};

visualizerCity::~visualizerCity(){};

void visualizerCity::initCity(const std::vector<infoRoad> &Rs)
{
    std::cout << "initCityAux, size of: " << Rs.size() << std::endl;
    // BUILD ROADS
    for (auto r : Rs)
    {
        // attrb
        sf::RectangleShape R;
        R.setSize(sf::Vector2(20.f, r.length));
        R.setFillColor(sf::Color{112, 112, 112, 255});

        // pos
        R.setOrigin(sf::Vector2f(10.f, r.length / 2.f));
        R.setPosition(r.pos.first, r.pos.second);
        R.rotate(r.angle);
    }

    // BUILD CROSSWALKS
    /*
    for(vector<crosswalk> Cs : crosswalk c) {
        sf::RectangleShape C;
        C.setSize(sf::Vector2(20.f, 10.f));
        C.setFillColor(sf::Color{255,255,255,255});
        C.setOrigin(sf::Vector2f(10.f, 5.f));
        C.setPosition(c.pos.first.f, c.pos.second.f);
        C.rotate(c.angle);

    }*/
}
void visualizerCity::draw(sf::RenderWindow *window)
{
    int size = this->Roads.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << "printing: " << i << std::endl;
        window->draw(Roads[i]);
    }
}
