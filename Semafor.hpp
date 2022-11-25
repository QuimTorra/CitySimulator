#ifndef CL_SEMAFOR
#define CL_SEMAFOR

#include <string>

class Semafor
{
    std::pair<int,int> Pos;
    int t_cotxes;
    int t_vianants;

public:
    Semafor();

    /**
     * @brief Constructs a new Semafor object
     * 
     * @param t_cotxes amount of seconds that the cars have to pass
     * @param t_vianants amount of seconds that the pedestrians have to pass
     */

    Semafor(int x, int y, int t_cotxes, int t_vianants);

    int get_t_cotxes();

    int get_t_vianants();

    std::pair<int,int> getPos();
};

#endif