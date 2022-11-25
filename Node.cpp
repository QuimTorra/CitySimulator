#include "Node.hpp"

Node::Node()
{
    this->name = "undefined";
}

Node::Node(std::string name)
{
    this->name = name;
}

std::string Node::get_name()
{
    return this->name;
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
}