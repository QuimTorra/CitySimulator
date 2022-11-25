#include "Road.hpp"

Road::Road(Node &origin, Node &end, std::string name, int max_speed)
{
    this->origin = origin;
    this->end = end;
    this->name = name;
    this->max_speed = max_speed;
}

Node Road::get_origin()
{
    return this->origin;
}

Node Road::get_end()
{
    return this->end;
}

std::string Road::get_name()
{
    return this->name;
}

int Road::get_max_speed()
{
    return this->max_speed;
}