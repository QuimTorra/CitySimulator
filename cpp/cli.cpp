#include <iostream>

#include "Road.hpp"
#include "Node.hpp"

using namespace std;
int main()
{
    Node n1 = Node("N1");
    Node n2 = Node("N2");

    Road r = Road(n1, n2, "Carrer Prova", 30);

    cout << "Carretera: " << r.get_origin().get_name();
    cout << " -> " << r.get_end().get_name() << " : ";
    cout << r.get_name() << " speed: " << r.get_max_speed() << endl;
}