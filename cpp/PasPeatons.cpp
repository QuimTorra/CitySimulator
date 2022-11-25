#include "PasPeatons.hpp"

PasPeatons::PasPeatons()
{
    this->t_cotxes  = 20;
    this->t_vianants  = 25;
}

PasPeatons::PasPeatons(std::int t_cotxes, std::int t_vianants)
{
    this->t_cotxes  = t_cotxes;
    this->t_vianants  = t_vianants;
}

std::string Node::get_name()
{
    return this->name;
}

std::int get_t_cotxes()
{
    return this->t_cotxes;
}

std::int get_t_vianants()
{
    return this->t_vianants;
}

