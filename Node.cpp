#include "Node.hpp"

Node::Node()
{
    this->name = "undefined";
}

Node::Node(std::string name, int x, int y)
{
    this->name = name;
    this->pos = std::pair(x, y);
}

std::string Node::get_name()
{
    return this->name;
}

std::pair<int, int> Node::get_pos()
{
    return this->pos;
}

std::vector<Node *> Node::get_connections()
{
    return this->connections;
}

std::map<std::string, Road> Node::get_roads()
{
    return this->roads;
}

void Node::add_connection(Node *n, Road r)
{
    this->connections.push_back(n);
    this->roads[n->get_name()] = r;
    r.set_start_pos(this->pos);
    r.set_end_pos(n->get_pos());
}