#include "Road.hpp"

Road::Road()
{
    this->name = "undefined";
    this->posStart = "undefined";
    this->posEnd = "undefined";
}

Road::Road(std::string name, int pStart, int pEnd, int max_speed)
{
    this->name = name;
    this->posStart = pStart;
    this->posEnd = pEnd;
    this->max_speed = max_speed;
}

std::string Road::get_name()
{
    return this->name;
}

float Road::get_length()
{
    float length (((x2 - x1)**2 +(y2 - y1)**2)**0.5);

    if (length < 0) {
        length = length*-1;
    }

    return length;
}

//mid point
int Road::getMidPoint()
{
    pair<int, int> midPoint;
    int x1 = posStart.first;
    int x2 = posStart.second;

    int y1 = posEnd.first;
    int y2 = posEnd.second;

    midPoint.first = (float)(x1+x2)/2;
    midPoint.second = (float)(y1+y2)/2; 

    return MidPoint;
}

//angle
float Road::getAngle() 
{
    float angle atan2(posStart.y - posEnd.y, posStart.x - posEnd.x).
    return angle;
}

//struc
struct Road:: getInfo()
{
    struct {             // Structure declaration
        pair<int, int> midPos;         // Member (int variable)
        float length;   // Member (string variable)
        float angle;
    } myStructure; 
    
    myStructure.midPos = this.getMidPoint;
    myStructure.length = this.get_length;
    myStructure.angle = this.getAngle;

    return myStructure;
};


int Road::get_max_speed()
{
    return this->max_speed;
}