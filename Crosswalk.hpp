#ifndef CL_CROSSWALK
#define CL_CROSSWALK

#include <string>

#include "Node.hpp"

class Crosswalk : public Node
{
    int t_cotxes;
    int t_vianants;
    //  std::semafor sem;
public:
    Crosswalk();

    /**
     * @brief Construct a new Crosswalk object
     *
     * @param id identifier of the Crosswalk
     */

    Crosswalk(std::string name, int t_cotxes, int t_vianants);

    int get_t_cotxes();

    int get_t_vianants();
};

#endif