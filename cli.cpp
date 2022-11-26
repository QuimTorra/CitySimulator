#include <iostream>

#include "City.hpp"
#include "Agent.hpp"

using namespace std;

void write(Agent a)
{
    cout << "<<------------------------------>>" << endl;
    cout << "Current: " << a.get_current_node()->get_name() << endl;
    cout << "Next: " << a.get_next_node()->get_name() << endl;
    cout << "Ticks to next: " << a.get_ticks_left() << endl;
}

int main()
{
    City prats = City("Prats de Lluçanès");

    Node n1 = prats.add_node("n1", 0, 0);
    Node n2 = prats.add_node("n2", 0, 1);

    Node n3 = Node("n3", 1, 1);
    prats.add_node(n3);

    prats.add_road("r12", n1, n2, 10);
    prats.add_road("r21", n2, n3, 10);
    prats.add_road("r31", n3, n1, 10);

    Agent car = Agent(n1, n3, 1);

    char a;
    cout << "<<------------------------------>>" << endl;
    cout << "Current: " << car.get_current_node()->get_name() << endl;

    while (cin >> a)
    {
        car.tick();
        write(car);
    }

    return 0;
}