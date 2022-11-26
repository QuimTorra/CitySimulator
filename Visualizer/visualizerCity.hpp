#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <utility>
#include <vector>
#include "../City.hpp"

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
    void move(float x, float y);
};