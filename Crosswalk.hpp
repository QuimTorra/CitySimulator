#ifndef CL_CROSSWALK
#define CL_CROSSWALK

#include <string>

#include "Node.hpp"
#include "Semafor.hpp"

class Crosswalk : public Node
{
    int t_cotxes;
    int t_vianants;
    //std::string name;
    Semafor sem;
public:
    Crosswalk();

    /**
     * @brief Construct a new Crosswalk object
     *
     * @param id identifier of the Crosswalk
     */

    Crosswalk(std::string name, int t_cotxes, int t_vianants);

    Crosswalk(std::string name, Semafor sem);

    int get_t_cotxes();

    int get_t_vianants();

    std::string get_name();

};

#endif