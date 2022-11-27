#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "visualizerCity.hpp"
#include "../Domain/City.hpp"
#include "Button.hpp"
#include "Menu.hpp"
#include "AgentManager.hpp"
#include <string>

// Simulation Engine

class Simulation
{
private:
    // var
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;

    Menu menu;
    Button addCar;
    Button removeCar;
    Button Quit;

    visualizerCity cityAux;
    AgentManager agents;
    City city;

    // func
    void initVariables();
    void initWindow();
    void initObjects();
    void inibtn();

public:
    Simulation();
    Simulation(std::string filepath);
    virtual ~Simulation();

    // func
    const bool running() const;
    void pollEvents();
    void update();
    void render();
};