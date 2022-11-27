#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>Bold
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
    bool sim_running;
    // var
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;

    Menu menu;

    Button start;
    Button stop;
    Button reset;
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

public:
    Simulation();
    Simulation(std::string filepath);
    virtual ~Simulation();

    // func
    const bool running() const;
    void pollEvents();
    void update();
    void render();

    void sim_start();
    void sim_stop();
    void sim_reset();
};