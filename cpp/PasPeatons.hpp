#ifndef CL_PASPEATONS
#define CL_PASPEATONS

#include <string>

class PasPeatons : public Node  
{
    std::int t_cotxes;
    std::int t_vianants;
//  std::semafor sem;
public:
    PasPeatons();

    /**
     * @brief Construct a new PasPeatons object
     * 
     * @param id identifier of the PasPeatons
    */

    PasPeatons(std::int t_cotxes, std::int t_vianants);

    std::string get_name();

    std::int get_t_cotxes();

    std::int get_t_vianants();

}