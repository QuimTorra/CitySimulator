#include "City.hpp"

City::City()
{
    this->name = "undefined";
}

City::City(std::string name)
{
    this->name = name;
}

std::vector<Node> City::get_nodes()
{
    return this->nodes;
}

std::vector<infoRoad> City::get_roads()
{
    int size = roads.size();
    std::vector<infoRoad> result(size);
    for (int i = 0; i < size; ++i)
    {

        result[i] = roads[i].get_info();
    }
    return result;
}

std::vector<infoRoad> City::get_rendering_info()
{
    return this->rendering_info;
}

Node City::add_node(std::string name, int x, int y)
{
    Node n = Node(name, x, y);
    this->nodes.push_back(n);
    return nodes[nodes.size() - 1];
}

void City::add_node(Node n)
{
    this->nodes.push_back(n);
}

void City::add_road(std::string name, Node &origin, Node &end, int max_speed)
{
    Road r = Road(name, max_speed);
    origin.add_connection(end, r);
    this->roads.push_back(r);
    this->rendering_info.push_back(r.get_info());
}