#include "Simulation.hpp"
// Simulation Engine

void Simulation::initVariables()
{
    this->window = nullptr;

    // create city
    this->city = City("Prats de Lluçanès");

    // X i despres Y
    Node n00 = this->city.add_node("n00", 100, 100);
    Node n01 = this->city.add_node("n00", 200, 100);
    Node n02 = this->city.add_node("n00", 300, 100);
    Node n03 = this->city.add_node("n00", 400, 100);
    Node n04 = this->city.add_node("n00", 500, 100);
    Node n10 = this->city.add_node("n00", 100, 200);
    Node n11 = this->city.add_node("n00", 200, 200);
    Node n12 = this->city.add_node("n00", 300, 200);
    Node n13 = this->city.add_node("n00", 400, 200);
    Node n14 = this->city.add_node("n00", 500, 200);
    Node n20 = this->city.add_node("n00", 100, 300);
    Node n21 = this->city.add_node("n00", 200, 300);
    Node n22 = this->city.add_node("n00", 300, 300);
    Node n23 = this->city.add_node("n00", 400, 300);
    Node n24 = this->city.add_node("n00", 500, 300);
    Node n30 = this->city.add_node("n00", 100, 400);
    Node n31 = this->city.add_node("n00", 200, 400);
    Node n32 = this->city.add_node("n00", 300, 400);
    Node n33 = this->city.add_node("n00", 400, 400);
    Node n34 = this->city.add_node("n00", 500, 400);

    // horitzontal
    this->city.add_road("r0", n00, n01, 1);
    this->city.add_road("r1", n01, n02, 1);
    this->city.add_road("r2", n02, n03, 1);
    this->city.add_road("r3", n03, n04, 1);
    this->city.add_road("r4", n10, n11, 1);
    this->city.add_road("r5", n11, n12, 1);
    this->city.add_road("r6", n12, n13, 1);
    this->city.add_road("r7", n13, n14, 1);
    this->city.add_road("r8", n20, n21, 1);
    this->city.add_road("r9", n21, n22, 1);
    this->city.add_road("r10", n22, n23, 1);
    this->city.add_road("r11", n23, n24, 1);
    this->city.add_road("r12", n30, n31, 1);
    this->city.add_road("r13", n31, n32, 1);
    this->city.add_road("r14", n32, n33, 1);
    this->city.add_road("r15", n33, n34, 1);

    // vertical
    this->city.add_road("v0", n00, n10, 1);
    this->city.add_road("v1", n10, n20, 1);
    this->city.add_road("v2", n20, n30, 1);
    this->city.add_road("v3", n01, n11, 1);
    this->city.add_road("v4", n11, n21, 1);
    this->city.add_road("v5", n21, n31, 1);
    this->city.add_road("v6", n02, n12, 1);
    this->city.add_road("v7", n12, n22, 1);
    this->city.add_road("v8", n22, n32, 1);
    this->city.add_road("v6", n03, n13, 1);
    this->city.add_road("v7", n13, n23, 1);
    this->city.add_road("v8", n23, n33, 1);
    this->city.add_road("v6", n04, n14, 1);
    this->city.add_road("v7", n14, n24, 1);
    this->city.add_road("v8", n24, n34, 1);

    // diagonal
    this->city.add_road("d1", n00, n11, 1);
    this->city.add_road("d2", n11, n22, 1);
    this->city.add_road("d3", n22, n33, 1);
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
    this->cityAux.initCity(city.get_roads());
    this->doSomething.init(920.f, 75.f, 140.f, 35.f, "Do Something");
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
        case sf::Event::MouseButtonReleased:
        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseMoved:
            this->doSomething.update(sf::Mouse::getPosition(*this->window));
            if (this->doSomething.isPressed())
            {
                std::cout << "Event activated" << std::endl;
            }
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
    this->window->clear(sf::Color{100, 200, 100, 255});

    // draw
    cityAux.draw(window);
    doSomething.draw(window);

    this->window->display();
}
