#ifndef CL_AGENT
#define CL_AGENT

#include "Node.hpp"
#include "City.hpp"
#include "Road.hpp"
#include <algorithm>

class Agent
{
    int state; // 0 in node, 1 traversing

    Node *current_pos;
    // Node destiny;

    int speed;
    int distance_left;
    City *city;
    Road act_road;
    Node *next;
    std::pair<int, int> draw_pos;

public:
    Agent();
    Agent(Node &starting_pos, /*  Node destiny, */ int speed, City *city);
    ~Agent() {}

    int get_state();

    Node *get_current_node();
    Node *get_next_node();

    float get_movingDistance();

    std::pair<int, int> get_draw_pos();
    float get_angle();
    void set_speed(int speed);

    std::pair<int, int> move_position(std::pair<int, int> origenPos, float angle);
    void tick(float movedDistance);

private:
    void bfs();
};

#endif