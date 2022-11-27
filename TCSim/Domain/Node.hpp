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
    std::vector<std::pair<std::string, Road>> connections;

public:
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
    std::vector<std::pair<std::string, Road>> get_connections();

    std::pair<std::string, Road> *get_random_connection();

    void add_connection(std::string node, std::pair<int, int> end_pos, Road r);
    // bool remove_connection(Node n);
};

#endif