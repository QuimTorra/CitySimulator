#define _USE_MATH_DEFINES

#include "Road.hpp"
#include <math.h>
#include <iostream>

Road::Road()
{
    this->name = "undefined";
}

Road::Road(std::string name, int max_speed, std::pair<int, int> origin, std::pair<int, int> end)
{
    this->name = name;
    this->max_speed = max_speed;
    this->posStart = origin;
    this->posEnd = end;
}

float Road::get_length()
{
    int x1 = this->posStart.first;
    int y1 = this->posStart.second;
    int x2 = this->posEnd.first;
    int y2 = this->posEnd.second;
    float m1 = (x2 - x1);
    float m2 = (y2 - y1);

    float length(sqrt(m1 * m1 + m2 * m2));

    if (length < 0)
    {
        length = length * -1;
    }

    return length;
}

// mid point
std::pair<int, int> Road::get_mid_point()
{
    std::pair<int, int> midPoint;
    int x1 = posStart.first;
    int y1 = posStart.second;

    int x2 = posEnd.first;
    int y2 = posEnd.second;

    midPoint.first = (float)(x1 + x2) / 2;
    midPoint.second = (float)(y1 + y2) / 2;

    return midPoint;
}

// angle
float Road::get_angle()
{
    float angle = atan2(posStart.second - posEnd.second, posStart.first - posEnd.first);
    return 90.f + angle * (180.f * M_1_PI);
}

// struc
infoRoad Road::get_info()
{
    infoRoad infoObject;

    infoObject.pos = this->get_mid_point();
    infoObject.length = this->get_length();
    infoObject.angle = this->get_angle();

    return infoObject;
};

std::string Road::get_name()
{
    return this->name;
}

int Road::get_max_speed()
{
    return this->max_speed;
}

void Road::set_start_pos(std::pair<int, int> pos)
{
    this->posStart = pos;
}

void Road::set_end_pos(std::pair<int, int> pos)
{
    this->posEnd = pos;
}