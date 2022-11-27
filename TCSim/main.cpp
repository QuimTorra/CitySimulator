#include "Visualizer/Simulation.hpp"

int main(int argc, char *argv[])
{
    std::string path = "./Data/csv_prova1.csv";
    if (argc > 1) {
        path = argv[2];
    }

    Simulation simulation = Simulation(path);

    while (simulation.running())
    {
        simulation.update();
        simulation.render();
    }

    return 0;
}

// g++ main.cpp Simulation.cpp ../City.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system