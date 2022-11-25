#ifndef CL_NODE
#define CL_NODE

#include <string>

class Node
{
  std::string name;

public:
  Node();

  /**
   * @brief Construct a new Node object
   *
   * @param name string representing the node
   */
  Node(std::string name);

  std::string get_name();
};

#endif