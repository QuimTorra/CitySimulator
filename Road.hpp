#ifndef CL_ROAD
#define CL_ROAD

#include <string>

class Road
{
    std::string name;
    pair<int, int> posStart;
    pair<int, int> posEnd;
    int max_speed;

public:
    Road();
    Road(std::string name, int length, int max_speed);

    std::string get_name();
    int get_length();
    int get_max_speed();
};

#endif