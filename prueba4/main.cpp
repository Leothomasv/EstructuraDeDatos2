#include <iostream>
#include <fstream>
#include <vector>
#include "Jzon.h"
#include "Yaml.hpp"



namespace Json = Jzon;
namespace Yml = Yaml;

std::string convert(const Json::Node& root){
    Yaml::Node padre;
    Yaml::Node ynode;
        if(root.isObject()){
            for (const auto& n : root)
            {
                //std::cout << n.first << " : ";
                Yaml::Node hijo = convert(n.second);
                ynode[n.first] = hijo;
                //std::cout << '\n';
            }
            ynode = padre.PushBack();
        }
        else if(root.isArray()){  
            bool first = true;
            for(const auto& n : root){
                if(first) first = false;

                Yaml::Node hijo2 = convert(n.second);
                ynode[n.first] = hijo2;
            }
            ynode = padre.PushBack();
        }else{
             ynode = Yaml::Node(root.toString());
             ynode = padre.PushBack();
        }


        Yaml::Serialize(padre,"file.yaml",Yaml::SerializeConfig(2,64,true,false));
}



int main(int argc, char *argv[])
{
    /*if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>\n";
        return 1;
    }*/

    Json::Parser parser;
    Json::Node root = parser.parseFile(argv[0]);

    convert(root);

    return 0;
}
