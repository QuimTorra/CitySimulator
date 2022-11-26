#ifndef CL_LECTOR
#define CL_LECTOR

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Lector
{
    std::string filename;
    std::vector<std::vector<std::string>> content;
    std::vector<std::string> row;
    std::string line, word;

public:
    Lector();

    Lector(std::string filename);

    bool llegir();

    std::vector<std::vector<std::string>> getContent();    

};
#endif