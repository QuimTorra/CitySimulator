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