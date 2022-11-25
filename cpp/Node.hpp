#ifndef CL_NODE
#define CL_NODE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Road.hpp"

class Node
{
  std::string name;
  std::vector<Road> sortides;

public:
  Node();

  /**
   * @brief Construct a new Node object
   *
   * @param name string representing the node
   */
  Node(std::string name);

  std::string get_name();

  void add_sortida(Road r);

  bool elimina_sortida(Road r);

  void quines_sortides();
};

#endif