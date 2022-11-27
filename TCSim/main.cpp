#include "Visualizer/Simulation.hpp"

int main(int argc, char *argv[])
{
    std::string path = "./Data/csv_provaLONDRES.csv";

    Simulation simulation = Simulation(path);

    while (simulation.running())
    {
        simulation.update();
        simulation.render();
    }

    return 0;
}

// g++ main.cpp Simulation.cpp ../City.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system