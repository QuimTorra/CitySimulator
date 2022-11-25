#include <iostream>

#include "Road.hpp"
#include "Node.hpp"

using namespace std;
int main()
{
    Node n1 = Node("N1");
    Node n2 = Node("N2");
    Node n3 = Node("N3");
    Node n4 = Node("N4");
    Node n5 = Node("N5");

    Road r1 = Road(n1, n2, "Carrer Prova", 30);
    Road r2 = Road(n2, n3, "Carrer Prova2", 40);
    Road r3 = Road(n3, n4, "Carrer Prova3", 20);
    Road r4 = Road(n4, n5, "Carrer Prova4", 15);
    Road r5 = Road(n5, n1, "Carrer Prova5", 10);
    Road r6 = Road(n4, n1, "Carrer Prova6", 5);
    Road r7 = Road(n5, n3, "Carrer Prova7", 70);
    Road r8 = Road(n1, n3, "Carrer Prova8", 120);

    n1.add_sortida(r1);
    n1.add_sortida(r8);
    n2.add_sortida(r2);
    n3.add_sortida(r3);
    n4.add_sortida(r6);
    n4.add_sortida(r4);
    n4.add_sortida(r5);
    n5.add_sortida(r7);

    cout << "El node 1 té les sortides "<< endl;
    n1.quines_sortides();
    cout << "El node 2 té les sortides "<< endl;
    n2.quines_sortides();
    cout << "El node 3 té les sortides "<< endl;
    n3.quines_sortides();
    cout << "El node 4 té les sortides "<< endl;
    n4.quines_sortides();
    cout << "El node 5 té les sortides "<< endl;
    n5.quines_sortides();
}