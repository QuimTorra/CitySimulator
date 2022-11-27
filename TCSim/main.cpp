#include "Visualizer/Simulation.hpp"

int main()
{
    // Init Simulation
    Simulation simulation = Simulation("./Data/csv_prova3.csv");

    // Game Loop
    while (simulation.running())
    {

        // Update
        simulation.update();

        simulation.render();
    }

    return 0;
}

// g++ main.cpp Simulation.cpp ../City.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system