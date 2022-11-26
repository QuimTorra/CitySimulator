#ifndef CL_ROAD
#define CL_ROAD

#include <string>
#include <cmath>
#include <utility>

class Road
{
    std::string name;
    std::pair<int, int> posStart;
    std::pair<int, int> posEnd;
    int max_speed;

public:
    Road();
    Road(std::string name, int max_speed);

    std::string get_name();
    float get_length();
    int get_max_speed();
    std::pair<int, int> get_mid_point();
    float get_angle();
    infoRoad get_info();

    void set_start_pos(std::pair<int, int> pos);
    void set_end_pos(std::pair<int, int> pos);
};

#endif