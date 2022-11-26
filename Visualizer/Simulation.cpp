#pragma once
#include "Simulation.hpp"
// Simulation Engine

void Simulation::initVariables()
{
    this->window = nullptr;

    // create city
    this->city = City("Prats de Lluçanès");

    Node n1 = this->city.add_node("n1", 0, 0);
    Node n2 = this->city.add_node("n2", 0, 1);

    Node n3 = Node("n3", 1, 1);
    this->city.add_node(n3);

    this->city.add_road("r12", n1, n2, 10);
    this->city.add_road("r21", n2, n3, 10);
    this->city.add_road("r31", n3, n1, 10);
}

void Simulation::initWindow()
{
    this->videoMode.height = 480;
    this->videoMode.width = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "City Simulator", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Simulation::initObjects()
{

    // load road objects for drawing
    cityAux.initCity(city.get_roads());
}

Simulation::Simulation()
{
    this->initVariables();
    this->initWindow();
    this->initObjects();
}
Simulation::~Simulation()
{
    delete this->window;
}

const bool Simulation::running() const
{
    return this->window->isOpen();
}

void Simulation::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            // send close window event
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Simulation::update()
{
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " ";
    // std::cout << sf::Mouse::getPosition().y << "\n";
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " ";
    // std::cout << sf::Mouse::getPosition(*this->window).y << "\n";

    this->pollEvents();
}

void Simulation::render()
{
    /*
        - clear old frames
        - render objects
        - display frame in window
    */
    this->window->clear();

    // draw
    cityAux.draw(window);

    this->window->display();
}
