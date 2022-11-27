#include "City.hpp"
#include "../Data/Lector.hpp"

using namespace std;

City::City() {}

City::City(std::string filename)
{
    Lector lec = Lector(filename);

    if (lec.llegir())
    {
        cout << "Sha llegit el document correctament. El seu contingut es: " << endl;
        bool first;
        std::vector<std::vector<std::string>> c = lec.getContent();
        for (int i = 0; i < c.size(); i++)
        {
            first = true;
            for (int j = 0; j < c[i].size(); j++)
            {
                if (first)
                {
                    cout << c[i][j];
                    first = false;
                    if (c[i][j] == "node")
                    {
                        std::cout << i << " " << j << "SAVE NODE" << endl;
                        Node n = Node(c[i][j + 1], stoi(c[i][j + 2]), stoi(c[i][j + 3]));
                        this->add_node(n);
                    }
                    else if (c[i][j] == "road")
                    {
                        std::cout << i << " " << j << "SAVE ROAD" << endl;
                        Node *n1 = this->get_node(c[i][j + 2]);
                        Node *n2 = this->get_node(c[i][j + 3]);
                        this->add_road(c[i][j + 1], *n1, *n2, stoi(c[i][j + 4]));
                    }
                }
                else
                {
                    cout << " " << c[i][j];
                    if (c[i][j] == "node")
                    {
                        Node n = Node(c[i][j + 1], stoi(c[i][j + 2]), stoi(c[i][j + 3]));
                        std::cout << i << " " << j << "SAVE ROAD" << endl;
                        this->add_node(n);
                    }
                    else if (c[i][j] == "road")
                    {
                        Node *n1 = this->get_node(c[i][j + 3]);
                        Node *n2 = this->get_node(c[i][j + 4]);
                        std::cout << i << " " << j << "SAVE ROAD" << endl;
                        this->add_road(c[i][j + 1], *n1, *n2, stoi(c[i][j + 2]));
                    }
                }
            }
            cout << endl;
        }
    }
    else
        cout << "El document no sha llegit correctament" << endl;
}

std::vector<Node> City::get_nodes()
{
    return this->nodes;
}

Node *City::get_randomNode()
{
    int idNode = (std::rand() % ((this->nodes.size() - 1) - 0 + 1));
    return &this->nodes[idNode];
}

std::vector<infoRoad> City::get_roads()
{
    std::cout << "1" << std::endl;
    int size = roads.size();
    std::cout << "2" << std::endl;
    std::vector<infoRoad> result(size);
    std::cout << "getting Roads: " << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "reading" << i << std::endl;
        result[i] = roads[i].get_info();
    }
    std::cout << "got roads" << std::endl;
    return result;
}

std::vector<infoNode> City::get_info_nodes()
{
    int size = this->nodes.size();
    std::vector<infoNode> result(size);
    std::cout << "reading nodes" << size << std::endl;

    std::cout << nodes[2].get_pos().first << std::endl;
    std::cout << nodes[2].get_pos().second << std::endl;
    std::cout << nodes[2].get_pos().second << std::endl;

    for (int i = 0; i < size; ++i)
    {

        result[i] = this->nodes[i].get_info();
        std::cout << "readed" << i << std::endl;
    }
    std::cout << "got" << std::endl;
    return result;
}

Node *City::get_node(std::string nomNode)
{
    std::vector<Node> n = get_nodes();
    for (int i = 0; i < n.size(); ++i)
    {
        if (n[i].get_name() == nomNode)
            return &nodes[i];
    }
    cout << "No sha trobat el node " << nomNode << endl;
    return nullptr;
}

std::vector<infoRoad> City::get_rendering_info()
{
    return this->rendering_info;
}

Node City::add_node(std::string name, int x, int y)
{
    Node n = Node(name, x, y);
    this->nodes.push_back(n);

    std::cout << "CHECKING NODE" << std::endl;
    std::cout << this->nodes[this->nodes.size() - 1].get_name() << " ";
    std::cout << this->nodes[this->nodes.size() - 1].get_pos().first << " ";
    std::cout << this->nodes[this->nodes.size() - 1].get_pos().second << " ";
    std::cout << std::endl;

    return nodes[nodes.size() - 1];
}

void City::add_node(Node n)
{
    this->nodes.push_back(n);

    std::cout << "CHECKING NODE" << std::endl;
    std::cout << this->nodes[this->nodes.size() - 1].get_name() << " ";
    std::cout << this->nodes[this->nodes.size() - 1].get_pos().first << " ";
    std::cout << this->nodes[this->nodes.size() - 1].get_pos().second << " ";
    std::cout << std::endl;
}

void City::add_road(std::string name, Node &origin, Node &end, int max_speed)
{
    Road r = Road(name, max_speed, origin.get_pos(), end.get_pos());
    origin.add_connection(end, r);
    this->roads.push_back(r);
    this->rendering_info.push_back(r.get_info());

    std::cout << "CHECKING ROAD" << std::endl;
    std::cout << this->roads[this->roads.size() - 1].get_name() << " ";
    std::cout << this->roads[this->roads.size() - 1].get_angle() << " ";
    std::cout << this->roads[this->roads.size() - 1].get_mid_point().first << " ";
    std::cout << this->roads[this->roads.size() - 1].get_mid_point().second << " ";
    std::cout << this->roads[this->roads.size() - 1].get_max_speed() << " ";
    std::cout << std::endl;
}
