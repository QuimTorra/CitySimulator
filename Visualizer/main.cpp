#include <iostream>
#include "Simulation.h"

int main()
{
    //Init Simulation
    Simulation simulation;
    
    //Game Loop
    while (simulation.running()) {

        //Update
        simulation.update(); 

        simulation.render(); 
    }

    return 0;
}