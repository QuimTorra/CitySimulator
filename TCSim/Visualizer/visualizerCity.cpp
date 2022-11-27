#include "visualizerCity.hpp"

visualizerCity::visualizerCity(){};

visualizerCity::~visualizerCity(){};

void visualizerCity::initCity(const std::vector<infoRoad> &Rs, const std::vector<infoNode> &Ns)
{
    int size = Rs.size();
    this->Roads = std::vector<sf::RectangleShape>(size);

    // BUILD ROADS
    for (int i = 0; i < size; ++i)
    {
        // attrb
        sf::RectangleShape R;
        R.setSize(sf::Vector2<float>(24.f, Rs[i].length));
        R.setFillColor(sf::Color{112, 112, 112, 255});

        // pos
        R.setOrigin(sf::Vector2f(12.f, Rs[i].length / 2.f));
        R.setPosition(Rs[i].pos.first, Rs[i].pos.second);
        R.rotate(Rs[i].angle);
        // R.setTexture(&this->texture);
        this->Roads[i] = R;
    }
    /*
    if (!texture.loadFromFile("crosswalkTexture.png"))
        std::cout << "error loading texture" << std::endl;
    size = Cs.size();
    this->CrossWalks = std::vector<sf::RectangleShape>(size);
    // BUILD CROSSWALKS
    for (int i = 0; i < size; ++i)
    {
        sf::RectangleShape C;
        C.setSize(sf::Vector2(24.f, 20.f));
        C.setOrigin(sf::Vector2f(12.f, 10.f));
        C.setPosition(c.pos.first.f, c.pos.second.f);
        C.rotate(c.angle);
        C.setTexture(&this->crosswalkTexture);
        this->CrossWalks[i] = C;
    }*/

    // Nodes
    size = Ns.size();
    this->Nodes = std::vector<sf::CircleShape>(size);
    // BUILD NODES
    for (int i = 0; i < size; ++i)
    {
        sf::CircleShape N;
        N.setRadius(12.f);
        N.setFillColor(sf::Color{112, 112, 112, 255});
        N.setOrigin(sf::Vector2f(12.f, 12.f));
        N.setPosition(Ns[i].pos.first, Ns[i].pos.second);
        this->Nodes[i] = N;
    }
}
void visualizerCity::draw(sf::RenderWindow *window)
{
    int size = this->Roads.size();
    for (int i = 0; i < size; ++i)
    {
        window->draw(Roads[i]);
    }
    /*
    size = this->CrossWalks.size();
    for (int i = 0; i < size; ++i)
    {
        window->draw(CrossWalks[i]);
    }*/

    size = this->Nodes.size();
    for (int i = 0; i < size; ++i)
    {
        window->draw(Nodes[i]);
    }
}