#ifndef CL_SIMULATION
#define CL_SIMULATION

#include "City.hpp"
#include "Agent.hpp"

class Simulation
{
    City city;
    std::vector<Agent> agents;

    int max_agents;

    float simulation_speed;

public:
    Simulation() {}
    Simulation(City city);
    ~Simulation();

    int get_max_agents();
    float get_simulation_speed();

    void set_max_agents(int max_agents);
    void set_simulation_speed(float speed);

    void tick();

private:
    void render();
};

#endif