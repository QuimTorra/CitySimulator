#include "Agent.hpp"

Agent::Agent() {}

Agent::Agent(Node &starting_pos, int speed, City *city)
{
    this->state = 0; // An agent always starts on a node
    this->city = city;
    this->next = &starting_pos;

    this->act_road = starting_pos.get_connections()[0].second;
    /* this->destiny = destiny; */
    this->speed = speed;
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

float Agent::get_movingDistance()
{
    float lowest_dist = float(speed);
    if (float(act_road.get_max_speed()) < lowest_dist)
        lowest_dist = float(act_road.get_max_speed());

    if (distance_left > 0 and distance_left < lowest_dist)
        return distance_left;
    return lowest_dist;
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

void Agent::tick(float movedDistance)
{
    if (this->state == 0)
    {
        this->current_pos = this->next;
        std::pair<std::string, Road> *conn = this->current_pos->get_random_connection();
        this->next = city->get_node((*conn).first);
        this->act_road = (*conn).second;
        this->distance_left = (*conn).second.get_length();

        this->state = 1;
    }
    if (this->state == 1)
    {
        distance_left = distance_left - movedDistance;
        // move position

        if (distance_left <= 0)
        {
            this->state = 0;
        }
    }
}