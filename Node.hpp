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
    std::pair<int, int> pos;
    std::vector<Node *> connections;
    std::map<std::string, Road> *roads = new std::map<std::string, Road>();

public:
    Node();

    /**
     * @brief Construct a new Node object
     *
     * @param name string representing the node
     */
    Node(std::string name, int x, int y);

    std::string get_name();
    std::pair<int, int> get_pos();
    std::vector<Node *> get_connections();

    Node *get_random_connection();

    Road get_road(std::string node_name);

    void add_connection(Node &n, Road r);
    // bool remove_connection(Node n);
};

#endif