#include "Road.hpp"

Road::Road()
{
    this->name = "undefined";
}

Road::Road(std::string name, int length, int max_speed)
{
    this->name = name;
    this->length = length;
    this->max_speed = max_speed;
}

std::string Road::get_name()
{
    return this->name;
}

int Road::get_length()
{
    return this->length;
}

int Road::get_max_speed()
{
    return this->max_speed;
}