#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>

class lexer{
private:
    std::ifstream readfile;
    std::string line;
    std::vector<std::vector<int>> cnf;
    
public:    
    lexer(std::string filename){
        readfile.open(filename);
        if(!readfile.is_open()){
            std::cerr << "Can not open file : " << filename << std::endl;
        }
    }

    void parse_line(std::string line)
    {

    }

};