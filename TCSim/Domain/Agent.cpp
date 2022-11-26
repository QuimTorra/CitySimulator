#include "Agent.hpp"

Agent::Agent() {}

Agent::Agent(Node starting_pos, int speed)
{
    this->state = 0; // An agent always starts on a node

    this->next = starting_pos;
    /* this->destiny = destiny; */
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

float Agent::get_angle() 
{
    return 1;
}

void Agent::set_speed(int speed)
{
    this->speed = speed;
}

std::pair<int, int> Agent::move_position(std::pair<int, int> origenPos, float angle) {
    std::pair<int, int> finalPos;
    
    //left
    if (0 == angle){
        finalPos.first = origenPos.first + this->speed;
        finalPos.second = origenPos.second;
    }
    //down
    else if (90 == angle){
        finalPos.first = origenPos.first;
        finalPos.second = origenPos.second - this->speed;
    }
    //rigth
    else if (180 == angle){
        finalPos.first = origenPos.first - this->speed;
        finalPos.second = origenPos.second;
    }
    //up
    else if (270 == angle){
        finalPos.first = origenPos.first;
        finalPos.second = origenPos.second + this->speed;
    }

    //DIAGONAL
    //Q1
    else if  (0 < angle and angle < 90) {
        finalPos.first = origenPos.first + this->speed * angle;
        finalPos.second = origenPos.second + this->speed * angle;
    }
    //Q2
    else if (90 < angle and angle < 180) {
        finalPos.first = origenPos.first + this->speed * angle;
        finalPos.second = origenPos.second + this->speed * angle;
    }
    //Q3
    else if (180 < angle and angle < 270) {
        finalPos.first = origenPos.first + this->speed * angle;
        finalPos.second = origenPos.second + this->speed * angle;
    }
    //Q4
    else {
        finalPos.first = origenPos.first + this->speed * angle;
        finalPos.second = origenPos.second + this->speed * angle;
    }

    return finalPos;
}

void Agent::tick()
{
    if (this->state == 0)
    {

        this->current_pos = this->next;
        std::pair<Node *, Road> conn = this->current_pos.get_random_connection();
        this->next = *(conn.first);
        this->draw_pos = std::pair<int, int>(this->next.get_pos());
        this->act_road = conn.second;
        this->ticks_left = conn.second.get_length();

        this->state = 1;
    }
    else if (this->state == 1)
    {
        this->ticks_left--;

        float angle = this->act_road.get_angle();

        //move position
        this->draw_pos = move_position(draw_pos, angle);

        if (ticks_left <= 0)
        {
            this->state = 0;
        }
    }
}