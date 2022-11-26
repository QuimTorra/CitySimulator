#include <iostream>

#include "City.hpp"
#include "Lector.hpp"

using namespace std;

int main()
{
    City prats = City("Prats de Lluçanès");

    Lector l1 = Lector("csv_prova.csv");

    if(l1.llegir()) 
    {
    cout<<"Sha llegit el document correctament. El seu contingut es: "<<endl;
    bool first;
    std::vector<std::vector<std::string>> c = l1.getContent();
    for (int i = 0; i < c.size(); i++) {
        first = true;
        for (int j = 0; j < c[i].size(); j++) {
            if(first){
                cout<<c[i][j];
                first = false;
                if(c[i][j] == "node") 
                {
                    Node n = Node(c[i][j+1],stoi(c[i][j+2]),stoi(c[i][j+3]));
                    prats.add_node(n);
                }
                else if(c[i][j] == "road") 
                {
                    Node n1 = prats.get_node(c[i][j+3]);
                    Node n2 = prats.get_node(c[i][j+4]);
                    prats.add_road(c[i][j+1],n1,n2,stoi(c[i][j+2]));
                }
            }
            else{
                cout<<" "<<c[i][j];
                if(c[i][j] == "node") 
                {
                    Node n = Node(c[i][j+1],stoi(c[i][j+2]),stoi(c[i][j+3]));
                    prats.add_node(n);
                }
                else if(c[i][j] == "road") 
                {
                    Node n1 = prats.get_node(c[i][j+3]);
                    Node n2 = prats.get_node(c[i][j+4]);
                    prats.add_road(c[i][j+1],n1,n2,stoi(c[i][j+2]));
                }
            }
        }
        cout<<endl;
        }
    }
    else cout<<"El document no sha llegit correctament"<<endl;

    std::vector<Node> nodes = prats.get_nodes();
    std::vector<infoRoad> inforoads = prats.get_roads(); 

    




















    /*

    Node n1 = prats.add_node("n1", 0, 0);
    Node n2 = prats.add_node("n2", 0, 1);
    Node n3 = prats.add_node("n3", 1, 0);
    Node n4 = prats.add_node("n4", 1, 1);
    prats.add_road("r12", n1, n2, 10);
    prats.add_road("r21", n2, n3, 10);
    prats.add_road("r31", n3, n1, 10);

    color c = Verd;
    Semafor s1 = Semafor("s1",5,5,25,20);
    color c1 = s1.get_color();
    s1.change_color(Verd);
    color c2 = s1.get_color();
    pair<int,int> posSemafor = s1.getPos();
    int tc = s1.get_t_cotxes();
    int tv = s1.get_t_vianants();

    cout<<"El color del semafor al inicialitzar-se es "<<to_string(c1)<<endl;
    cout<<"El color del semafor ha cambiat a "<<to_string(c2)<<endl;
    cout<<"La posicio del semàfor es x: "<<posSemafor.first<<" y: "<<posSemafor.second<<endl;
    cout<<"El temps del semafor perque creuin vianants es: "<<tv<<endl;
    cout<<"El temps del semafor perque creuin cotxes es: "<<tc<<endl;

    Crosswalk cr1 = Crosswalk("CrosswalkSenseSemafor", 20, 25, 7, 7);    
    Crosswalk cr2 = Crosswalk("CrosswalkAmbSemafor", s1);

    pair<int,int> posCrosswalkSenseSem = cr1.get_pos();
    /*
    int tc1 = cr1.get_t_cotxes();
    int tv1 = cr1.get_t_vianants();

    pair<int,int> posCrosswalkAmbSem = cr2.get_pos();
    /*
    int tc2 = cr2.get_t_cotxes();
    int tv2 = cr2.get_t_vianants();

    cout<<"La posicio del crosswalk sense semafor es x: "<<posCrosswalkSenseSem.first<<" y: "<<posCrosswalkSenseSem.second<<endl;
    cout<<"El tcotxes del crosswalk sense semafor es: "<<tc1<<endl;
    cout<<"El tvianants del crosswalk sense semafor es: "<<tv1<<endl;
    
    cout<<"La posicio del crosswalk amb semafor es x: "<<posCrosswalkAmbSem.first<<" y: "<<posCrosswalkAmbSem.second<<endl;
    cout<<"El tcotxes del crosswalk amb semafor es: "<<tc2<<endl;
    cout<<"El tvianants del crosswalk amb semafor es: "<<tv2<<endl;*/

    

    
    return 0;

}