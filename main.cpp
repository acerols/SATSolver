#include <iostream>
#include <string>
#include <fstream>
#include <boost/spirit/include/qi.hpp>


int main(int argc, char *argv[])
{
    std::string line;
    if(argc < 2){
        std::cout << "Insufficient arguments" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];

    std::ifstream readfile(filename);

    if(readfile.is_open()){
        while(getline(readfile, line)){
            std::cout << line << std::endl;
        }
        readfile.close();
    }
    else std::cout << "Error Can not read file : " << filename << std::endl;
    return 0;
    

}