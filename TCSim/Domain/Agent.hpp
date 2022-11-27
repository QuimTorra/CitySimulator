#ifndef CL_AGENT
#define CL_AGENT

#include "Node.hpp"
#include "Road.hpp"

class Agent
{
    int state; // 0 in node, 1 traversing

    Node current_pos;
    // Node destiny;

    int nodes_left;

    int speed;
    int ticks_left;
    Road act_road;
    Node next;
    std::pair<int, int> draw_pos;

public:
    Agent();
    Agent(Node starting_pos, /*  Node destiny, */ int speed);
    ~Agent() {}

    int get_state();

    Node get_current_node();
    Node get_next_node();

    int get_speed();
    int get_nodes_left();
    int get_ticks_left();
    std::pair<int, int> get_draw_pos();
    float get_angle();
    void set_speed(int speed);

    std::pair<int, int> move_position(std::pair<int, int> origenPos, float angle);
    void tick();

private:
    void bfs();
};

#endif