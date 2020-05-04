#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>


class lexer{
private:
    std::ifstream readfile;
    std::vector<std::vector<int>> cnf;
    int var;
    int formula;
    
public:    
    lexer(std::string filename);
    void parse_line(std::string line);

    

};

#endif