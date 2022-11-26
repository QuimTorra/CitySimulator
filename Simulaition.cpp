#include "Simulation.hpp"

Simulation::Simulation(City city, int max_agents)
{
    this->city = city;
    this->max_agents = max_agents;
}

int Simulation::get_max_agents()
{
    return this->max_agents;
}

float Simulation::get_simulation_speed()
{
    return this->simulation_speed;
}

void Simulation::set_max_agents(int max_agents)
{
    this->max_agents = max_agents;
}

void Simulation::set_simulation_speed(float speed)
{
    this->simulation_speed = speed;
}

void Simulation::tick()
{
}