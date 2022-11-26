#include "City.hpp"
#include "../Data/Lector.hpp"

using namespace std;

City::City()
{
    this->name = "undefined";
}

City::City(std::string filename)
{
    this->name = filename;
    Lector lec = Lector(filename);

    if(lec.llegir())
    {
    cout<<"Sha llegit el document correctament. El seu contingut es: "<<endl;
    bool first;
    std::vector<std::vector<std::string>> c = lec.getContent();
    for (int i = 0; i < c.size(); i++) {
        first = true;
        for (int j = 0; j < c[i].size(); j++) {
            if(first){
                cout<<c[i][j];
                first = false;
                if(c[i][j] == "node")
                {
                    Node n = Node(c[i][j+1],stoi(c[i][j+2]),stoi(c[i][j+3]));
                    this->add_node(n);
                }
                else if(c[i][j] == "road")
                {
                    Node *n1 = this->get_node(c[i][j+3]);
                    Node *n2 = this->get_node(c[i][j+4]);
                    this->add_road(c[i][j+1],*n1,*n2,stoi(c[i][j+2]));
                }
            }
            else{
                cout<<" "<<c[i][j];
                if(c[i][j] == "node")
                {
                    Node n = Node(c[i][j+1],stoi(c[i][j+2]),stoi(c[i][j+3]));
                    this->add_node(n);
                }
                else if(c[i][j] == "road")
                {
                    Node *n1 = this->get_node(c[i][j+3]);
                    Node *n2 = this->get_node(c[i][j+4]);
                    this->add_road(c[i][j+1],*n1,*n2,stoi(c[i][j+2]));
                }
            }
        }
        cout<<endl;
        }
    }
    else cout<<"El document no sha llegit correctament"<<endl;
}

std::vector<Node> City::get_nodes()
{
    return this->nodes;
}

std::vector<infoRoad> City::get_roads()
{
    int size = roads.size();
    std::vector<infoRoad> result(size);
    for (int i = 0; i < size; ++i)
    {

        result[i] = roads[i].get_info();
    }
    return result;
}

std::vector<infoNode> City::get_info_nodes()
{
    int size = this->nodes.size();
    std::vector<infoNode> result(size);
    for (int i = 0; i < size; ++i)
    {

        result[i] = this->nodes[i].get_info();
    }
    return result;
}

Node City::get_node(std::string nomNode)
{
    std::vector<Node> n = get_nodes();
    for (int i = 0; i < n.size(); ++i)
    {
        if (n[i].get_name() == nomNode)
            return nodes[i];
    }
    cout << "No sha trobat el node " << nomNode << endl;
    return Node();
}

std::string City::get_nom()
{
    return this->name;
}

std::vector<infoRoad> City::get_rendering_info()
{
    return this->rendering_info;
}

Node City::add_node(std::string name, int x, int y)
{
    Node n = Node(name, x, y);
    this->nodes.push_back(n);
    return nodes[nodes.size() - 1];
}

void City::add_node(Node n)
{
    this->nodes.push_back(n);
}

void City::add_road(std::string name, Node &origin, Node &end, int max_speed)
{
    Road r = Road(name, max_speed, origin.get_pos(), end.get_pos());
    origin.add_connection(end, r);
    this->roads.push_back(r);
    this->rendering_info.push_back(r.get_info());
}
