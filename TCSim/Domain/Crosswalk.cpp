#include "Crosswalk.hpp"

Crosswalk::Crosswalk()
{
    this->t_cotxes = 20;
    this->t_vianants = 25;
}

Crosswalk::Crosswalk(std::string name, int t_cotxes, int t_vianants, int x, int y)
    : Node(name, x, y)
{
    this->t_cotxes = t_cotxes;
    this->t_vianants = t_vianants;
    //this->name = Node(name);
}

Crosswalk::Crosswalk(std::string name, Semafor sem)
    : Node(name, sem.getPos().first, sem.getPos().second)
{
    this->t_cotxes = sem.get_t_cotxes();
    this->t_vianants = sem.get_t_vianants();
}

int Crosswalk::get_t_cotxes()
{
    return this->t_cotxes;
}
 
int Crosswalk::get_t_vianants()
{
    return this->t_vianants;
}

/*std::string Crosswalk::get_name(){
    return Node(name);
}*/
