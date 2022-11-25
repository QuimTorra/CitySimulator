#include "Crosswalk.hpp"

Crosswalk::Crosswalk()
{
    this->t_cotxes = 20;
    this->t_vianants = 25;
}

Crosswalk::Crosswalk(std::string name, int t_cotxes, int t_vianants)
    : Node(name)
{
    this->t_cotxes = t_cotxes;
    this->t_vianants = t_vianants;
}

int Crosswalk::get_t_cotxes()
{
    return this->t_cotxes;
}

int Crosswalk::get_t_vianants()
{
    return this->t_vianants;
}
