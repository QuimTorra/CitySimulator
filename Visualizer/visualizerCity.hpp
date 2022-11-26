#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct road {
    pair<int,int> pos;
    float lenght;
    float angle;
};

struct crosswalk {
    pair<int,int> pos;
    float angle;
};

class visualizerCity 
{
private:
    //var
    vector<sf::RectangleShape> Roads;
    
public:
    void visualizerCity();
    void ~visualizerCity();
    
    void initCity(const vector<road>& Rs, const vector<crosswalk>& Cs);
    void draw(sf::RenderWindow window);
 };