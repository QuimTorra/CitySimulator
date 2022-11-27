#ifndef CL_NODE
#define CL_NODE

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Road.hpp"

struct infoNode
{
    std::pair<int, int> pos;
    float angle;
};

class Node
{
    std::string name;
    std::pair<int, int> pos;
    std::vector<std::pair<Node *, Road>> connections;

public:
    Node();
    ~Node() {}

    /**
     * @brief Construct a new Node object
     *
     * @param name string representing the node
     */
    Node(std::string name, int x, int y);

    infoNode get_info();

    std::string get_name();
    std::pair<int, int> get_pos();
    std::vector<std::pair<Node *, Road>> get_connections();

    std::pair<Node *, Road> *get_random_connection();

    void add_connection(Node &n, Road r);
    // bool remove_connection(Node n);
};

#endif