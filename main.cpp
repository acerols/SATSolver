#include <iostream>
#include <string>
#include <fstream>
#include <boost/spirit/include/qi.hpp>

#include "lexer.hpp"
#include "core.hpp"

int main(int argc, char *argv[])
{
    std::string line;
    if(argc < 2){
        std::cout << "Insufficient arguments" << std::endl;
        return 1;
    }
    
    lexer *lex = new lexer;
    lex->lex(argv[1]);
    clauses cls = lex->getClauses();
    

        //debug console
    for(auto i = 0; i < cls.CNF.size(); i++){
        std::cout << "Literal=" << i << " : ";
        for(auto j = 1; j < cls.CNF.at(i).size(); j++){
            std::cout << j << "=" << cls.CNF.at(i).at(j) << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    DPLL core(cls);
    if(core.FullSearch() == SAT){
        std::cout << "SAT" << std::endl;
    }
    else{
        std::cout << "UNSAT" << std::endl;
    }

    return 0;

}