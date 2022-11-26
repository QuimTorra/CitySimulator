#include <iostream>

#include "City.hpp"
#include "Agent.hpp"

using namespace std;

int main()
{
    City prats = City("Prats de Lluçanès");
    Node n1 = prats.add_node("n1", 0, 0);
    Node n2 = prats.add_node("n2", 0, 1);
    Node n3 = prats.add_node("n3", 1, 0);
    Node n4 = prats.add_node("n4", 1, 1);
    prats.add_road("r12", n1, n2, 10);
    prats.add_road("r21", n2, n3, 10);
    prats.add_road("r31", n3, n1, 10);

    Agent car = Agent(n1, n3, 1);

    char a;

    while (cin >> a)
    {
        car.tick();
        write(car);
    }

    return 0;
}