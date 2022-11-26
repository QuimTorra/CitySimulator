#ifndef CL_AGENT
#define CL_AGENT

#include "Node.hpp"

class Agent
{
    Node *current_pos;
    Node *destiny;

    int speed;

public:
    Agent();
    Agent(Node *starting_pos, Node *destiny, int speed);
}

#endif