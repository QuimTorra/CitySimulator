#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "visualizerCity.hpp"
#include "../City.hpp"


//Simulation Engine

class Simulation 
{
private:
    //var
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    visualizerCity cityAux;
    City city;

    //
    sf::RectangleShape car;

    //func
    void initVariables();
    void initWindow();
    void initObjects();
    
public:
        Simulation();
        virtual ~Simulation();

        //func
        const bool running() const;
        void pollEvents();
        void update();
        void render();
};