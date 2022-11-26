#include "Visualizer/Simulation.hpp"

int main()
{
    // Init Simulation
    Simulation simulation;

    // Game Loop
    while (simulation.running())
    {

        // Update
        simulation.update();

        simulation.render();
    }

    return 0;
}