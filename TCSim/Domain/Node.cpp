#include "Node.hpp"

Node::Node()
{
    this->name = "undefined";
}

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

std::vector<std::pair<Node *, Road>> Node::get_connections()
{
    return this->connections;
}

std::pair<Node *, Road> Node::get_random_connection()
{
    int id = (std::rand() % ((this->connections.size() - 1) - 0 + 1));
    std::cout << id << " : " << this->connections.size() << std::endl;
    return this->connections[id];
}

void Node::add_connection(Node &n, Road r)
{
    this->connections.push_back(std::pair<Node *, Road>(&n, r));
    r.set_start_pos(this->pos);
    r.set_end_pos(n.get_pos());
}

infoNode Node::get_info()
{
    infoNode result;
    result.pos = this->pos;
    result.angle = this->connections[0].second.get_angle();
}