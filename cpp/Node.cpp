#include "Node.hpp"

Node::Node()
{
    this->name = "undefined";
}

Node::Node(std::string name)
{
    this->name = name;
}

std::string Node::get_name()
{
    return this->name;
}

void Node::add_sortida(Road r)
{
    sortides.push_back(r);

}

bool Node::elimina_sortida(Road r)
{
    std::vector<Road>::iterator it;
    it = find(sortides.begin(), sortides.end(), r);
    if(it != sortides.end()) {
        sortides.erase(it);
        return true;
    }
    else return false;
}

void Node::quines_sortides()
{
    std::vector<Road>::iterator it = sortides.begin();
    int x = 0;
    while(it != sortides.end()){
        std::cout<<"La sortida "<<x<<" del node "<<get_name()<< " és el carrer "<<(*it).get_name();
        std::advance(it,1);
    }
}