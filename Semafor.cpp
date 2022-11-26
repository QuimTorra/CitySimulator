#include "Semafor.hpp"

Semafor::Semafor(int x, int y, int t_cotxes, int t_vianants)
{
    std::pair<int,int> p;
    p.first = x;
    p.second = y;
    this->Pos = p;
    this->t_cotxes = t_cotxes;
    this->t_vianants = t_vianants;
    this->c = Vermell;
}

int Semafor::get_t_cotxes()
{
    return this->t_cotxes;
}

int Semafor::get_t_vianants()
{
    return this->t_vianants;
}

std::pair<int,int> Semafor::getPos()
{
    return this->Pos;
}


color Semafor::get_color()
{
    return this->c;
}

void Semafor::change_color(color co)
{
    this->c = co;
}