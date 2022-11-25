#ifndef CL_ROAD
#define CL_ROAD

#include "Node.hpp"

class Road
{
  Node origin;
  Node end;

  std::string name;
  int max_speed;

public:
  // Constructors
  /**
   * @brief Construct a new Road object
   *
   * @param origin The starting Node of the road
   * @param end The ending Node of the road
   * @param name Name of the road
   * @param max_speed Max speed of the road
   */
  Road(Node &origin, Node &end, std::string name, int max_speed);

  // Getters
  Node get_end();
  Node get_origin();
  std::string get_name();
  int get_max_speed();

  // Setters
};

#endif