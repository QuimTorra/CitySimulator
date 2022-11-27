#include "Node.hpp"

Node::Node(std::string name, int x, int y)
{
    this->name = name;
    this->pos = std::pair<int, int>(x, y);
}

std::string Node::get_name()
{
    return this->name;
}

std::pair<int, int> Node::get_pos()
{
    return this->pos;
}

std::vector<std::pair<std::string, Road>> Node::get_connections()
{
    return this->connections;
}

std::pair<std::string, Road> *Node::get_random_connection()
{
    // int id = (std::rand() % ((this->connections.size() - 1) - 0 + 1));
    std::cout << "getNext: " << connections[0].first << std::endl;
    return &connections[0];
}

void Node::add_connection(std::string node, std::pair<int, int> end_pos, Road r)
{
    r.set_start_pos(this->pos);
    r.set_end_pos(end_pos);
    this->connections.push_back(std::pair<std::string, Road>(node, r));
    std::cout << "added_connection: " << &this->connections[this->connections.size() - 1] << std::endl;
}

infoNode Node::get_info()
{
    infoNode result;
    result.pos = this->pos;
    if (&this->connections[0] == 0)
        std::cout << "ERROR: DEAD-END!" << std::endl;
    result.angle = this->connections[0].second.get_angle();
    return result;
}