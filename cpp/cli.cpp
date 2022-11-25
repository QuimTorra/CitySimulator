#include <iostream>

#include "Road.hpp"
#include "PasPeatons.hpp"

using namespace std;
int main()
{
    Node n1 = Node("N1");
    Node n2 = Node("N2");

    Road r = Road(n1, n2, "Carrer Prova", 30);

    PasPeatons p1 = Pas(25,25);

    cout << "Carretera: " << r.get_origin().get_name();
    cout << " -> " << r.get_end().get_name() << " : ";
    cout << r.get_name() << " speed: " << r.get_max_speed() << endl;
    cout << p1.get_name() << " speed for cars: " 
    << p1.get_t_cotxes() << " speed for pedestrians: " 
    << p1.get_t_vianants() << endl;

}