#pragma once
#include "Simulation.h"
//Simulation Engine

void Simulation::initVariables() {
    this->window = nullptr;

}

void Simulation::initWindow() {
    this->videoMode.height = 480;
    this->videoMode.width = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "City Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Simulation::initObjects() {

    //attrb
    this->car.setSize(sf::Vector2(50.f, 25.f));
    this->car.setFillColor(sf::Color{0, 33, 217, 255});
    this->car.setOutlineColor(sf::Color{0, 13, 87, 255});
    this->car.setOutlineThickness(3.f);

    //pos
    this->car.setOrigin(sf::Vector2f(this->car.getLocalBounds().width, this->car.getLocalBounds().height) / 2.f);
    this->car.setPosition(10.f, 10.f);
}

Simulation::Simulation() {
    this->initVariables();
    this->initWindow();
    this->initObjects();
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
            if (this->ev.key.code == sf::Keyboard::Left) this->car.rotate(-5.f);
            else if (this->ev.key.code == sf::Keyboard::Right) this->car.rotate(5.f);
            if (this->ev.key.code == sf::Keyboard::Up) this->car.move(1.f, 0.f);
            else if (this->ev.key.code == sf::Keyboard::Down) this->car.move(1.f, 0.f);
            break;
        }
    }
}

void Simulation::update() {
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "; 
    //std::cout << sf::Mouse::getPosition().y << "\n";
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " ";
    //std::cout << sf::Mouse::getPosition(*this->window).y << "\n";

    this->pollEvents();
}

void Simulation::render() {
    /*
        - clear old frames
        - render objects
        - display frame in window
    */
    this->window->clear();

    //draw
    this->window->draw(this->car);

    this->window->display();
}
