#include "Agent.hpp"

Agent::Agent() {}

Agent::Agent(Node starting_pos, Node destiny, int speed)
{
    this->state = 0; // An agent always starts on a node

    this->next = starting_pos;
    this->destiny = destiny;
    this->speed = speed;

    this->draw_pos = std::pair<int, int>(starting_pos.get_pos());
}

int Agent::get_state()
{
    return this->state;
}

Node Agent::get_current_node()
{
    return this->current_pos;
}

Node Agent::get_next_node()
{
    return this->next;
}

int Agent::get_speed()
{
    return this->speed;
}

int Agent::get_nodes_left()
{
    return this->nodes_left;
}

int Agent::get_ticks_left()
{
    return this->ticks_left;
}

std::pair<int, int> Agent::get_draw_pos()
{
    return this->draw_pos;
}

void Agent::set_speed(int speed)
{
    this->speed = speed;
}

void Agent::tick()
{
    if (this->state == 0)
    {
        this->current_pos = this->next;
        std::pair<Node *, Road> conn = this->current_pos.get_random_connection();
        this->next = *(conn.first);
        this->ticks_left = conn.second.get_length();

        this->state = 1;
    }
    else if (this->state == 1)
    {
        this->ticks_left--;

        if (ticks_left <= 0)
        {
            this->state = 0;
        }
    }
}