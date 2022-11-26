#include <iostream>

#include "City.hpp"

using namespace std;

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

    return 0;
}