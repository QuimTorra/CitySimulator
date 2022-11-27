#include "Agent.hpp"
#include <assert.h>

Agent::Agent() {}

Agent::Agent(Node &starting_pos, int speed, City *city)
{
    this->state = 0; // An agent always starts on a node
    this->city = city;
    this->next = &starting_pos;
    this->current_pos = &starting_pos;

    this->act_road = starting_pos.get_connections()[0].second;
    /* this->destiny = destiny; */
    this->speed = speed;

    this->draw_pos = std::pair<int, int>(starting_pos.get_pos());
}

int Agent::get_state()
{
    return this->state;
}

Node *Agent::get_current_node()
{
    return this->current_pos;
}

Node *Agent::get_next_node()
{
    return this->next;
}

int Agent::get_speed()
{
    return this->speed;
}

int Agent::get_ticks_left()
{
    return this->ticks_left;
}

std::pair<int, int> Agent::get_draw_pos()
{
    return this->draw_pos;
}

float Agent::get_angle()
{
    return this->act_road.get_angle();
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
        std::pair<std::string, Road> *conn = this->current_pos->get_random_connection();
        this->next = city->get_node((*conn).first);
        this->act_road = (*conn).second;
        this->ticks_left = (*conn).second.get_length() / this->speed;

        this->state = 1;
    }
    else if (this->state == 1)
    {
        this->ticks_left--;

        // move position

        if (ticks_left <= 0)
        {
            this->state = 0;
        }
    }
}