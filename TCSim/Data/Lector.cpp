#include "Lector.hpp"

Lector::Lector(std::string filenam)
{
    this->filename = filenam;
}

bool Lector::llegir()
{
    std::fstream file (filename, std::ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
 
            std::stringstream str(line);
 
            while(getline(str, word, ','))
            row.push_back(word);
            content.push_back(row);
        }
        return true;
    }
    else return false;
    
}

std::vector<std::vector<std::string>> Lector::getContent()
{
    return this->content;
}