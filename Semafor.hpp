#ifndef CL_SEMAFOR
#define CL_SEMAFOR

#include <string>

enum color
{
    Vermell,
    Groc,
    Verd
};

class Semafor
{
    std::string nom;
    std::pair<int,int> Pos;
    int t_cotxes;
    int t_vianants;
    int i_groc;
    color c;

public:
    Semafor() {}
    ~Semafor() {}

    /**
     * @brief Constructs a new Semafor object
     *
     * @param t_cotxes amount of seconds that the cars have to pass
     * @param t_vianants amount of seconds that the pedestrians have to pass
     */

    Semafor(std::string nom, int x, int y, int t_cotxes, int t_vianants);

    int get_t_cotxes();

    int get_t_vianants();

    color get_color();

    void change_color(color co);

    std::pair<int, int> getPos();
};

#endif