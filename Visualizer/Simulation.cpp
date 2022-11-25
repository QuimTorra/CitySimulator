#pragma oncec
#include "Simulation.h"
//Simulation Engine

void Simulation::initVariables() {
    this->window = nullptr;

}

void Simulation::initWindow() {
    this->videoMode.height = 420;
    this->videoMode.width = 780;
    this->window = new sf::RenderWindow(this->videoMode, "City Simulator", sf::Style::Titlebar | sf::Style::Close);
}

Simulation::Simulation() {
    this->initVariables();
    this->initWindow();
}
Simulation::~Simulation() {
    delete this->window;
}

const bool Simulation::running() const {
    return this->window->isOpen();
}

void Simulation::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch(this->ev.type) 
        {
        case sf::Event::Closed:
            //send close window event
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape) this->window->close();
            break;
        }
    }
}

void Simulation::update() {
    
    this->pollEvents();
}

void Simulation::render() {
    /*
        - clear old frames
        - render objects
        - display frame in window
    */
    this->window->clear();

    this->window->display();
}
