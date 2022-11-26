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

void Simulation::iniAgents() {

    int numA = this->max_agents;

    for (int i = 0; i < numA; ++i) {
        //const speed 1
        std::vector<Node> nodes = city.get_nodes();
        //random node
        int idNode = (std::rand() % ((nodes.size() - 1) - 0 + 1));

        Agent a = Agent(nodes[idNode], 1);
        this->agents.push_back(a);
    }
}

/* 
visual ticks
 */
void Simulation::tick()
{
    int numA = this->max_agents;
    for (int i = 0; i < numA; ++i) {
        this->agents[i].tick();
        std::pair<int, int> aPos = this->agents[i].get_draw_pos();

        //render
    }
}
