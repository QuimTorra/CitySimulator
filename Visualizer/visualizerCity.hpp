#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <utility>
#include <vector>

struct infoRoad
{
    std::pair<int, int> pos;
    float lenght;
    float angle;
};

class visualizerCity
{
private:
    // var
    std::vector<sf::RectangleShape> Roads;

public:
    visualizerCity();
    ~visualizerCity();

    void initCity(const std::vector<infoRoad> &Rs);
    void draw(sf::RenderWindow *window);
};