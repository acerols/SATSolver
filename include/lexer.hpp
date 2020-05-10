#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

typedef struct{
    std::vector<std::vector<int>> CNF;
    int numVar;
    int numLiteral;
}clauses;

class lexer{
private:
    std::ifstream readfile;
    clauses cnf;
public:    
    lexer(std::string filename);
    void parse_line(std::string line);    
    
};

#endif
