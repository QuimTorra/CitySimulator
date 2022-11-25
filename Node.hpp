#ifndef CL_NODE
#define CL_NODE

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Road.hpp"

class Node
{
    std::string name;
    std::vector<Node *> connections;
    std::map<std::string, Road> roads;

public:
    Node();

    /**
     * @brief Construct a new Node object
     *
     * @param name string representing the node
     */
    Node(std::string name);

    std::string get_name();
    std::vector<Node *> get_connections();
    std::map<std::string, Road> get_roads();

    void add_connection(Node *n, Road r);
    // bool remove_connection(Node n);
};

#endif