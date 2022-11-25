#include <iostream>

#include "Road.hpp"
#include "Node.hpp"

using namespace std;

int main()
{
    Node n1 = Node("n1");
    Node n2 = Node("n2");
    Node n3 = Node("n3");

    Road r12 = Road("r12", 1, 1);
    Road r23 = Road("r23", 1, 1);
    Road r31 = Road("r31", 1, 1);

    n1.add_connection(&n2, r12);
    n2.add_connection(&n3, r23);
    n3.add_connection(&n1, r31);

    Node *currentNode = &n1;

    string a;
    cout << currentNode->get_name() << endl;
    while (cin >> a)
    {
        currentNode = currentNode->get_connections()[0];
        cout << currentNode->get_name() << endl;
    }
}