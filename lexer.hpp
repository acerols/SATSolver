#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>

class lexer{
private:
    std::ifstream readfile;
    std::vector<std::vector<int>> cnf;
    
public:    
    lexer(std::string filename){
        std::string line;
        readfile.open(filename);
        if(!readfile.is_open()){
            std::cerr << "Can not open file : " << filename << std::endl;
        }
        while(getline(readfile, line)){
            parse_line(line);
        }
    }

    void parse_line(std::string line)
    {
        std::cout << line << std::endl;
    }

};