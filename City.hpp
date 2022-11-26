#ifndef CL_CITY
#define CL_CITY

#include "Node.hpp"
#include "Road.hpp"
#include "Crosswalk.hpp"
#include "Semafor.hpp"
#include <utility>
#include <vector>

class City
{
    std::string name;
    std::vector<Node> nodes;
    std::vector<Road> roads;
    std::vector<infoRoad> rendering_info;

public:
    City();
    City(std::string name);

    std::vector<Node> get_nodes();
    std::vector<infoRoad> get_roads();
    std::vector<infoRoad> get_rendering_info();

    Node add_node(std::string name, int x, int y);
    void add_node(Node n);
    void add_road(std::string name, Node &origin, Node &end, int max_speed);
};

#endif