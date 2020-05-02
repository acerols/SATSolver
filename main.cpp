#include <iostream>
#include <string>
#include <fstream>
#include <boost/spirit/include/qi.hpp>

#include "lexer.hpp"

int main(int argc, char *argv[])
{
    std::string line;
    if(argc < 2){
        std::cout << "Insufficient arguments" << std::endl;
        return 1;
    }
    
    lexer lex(argv[1]);
    
    return 0;

}