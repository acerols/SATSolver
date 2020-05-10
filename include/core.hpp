#ifndef __CORE_HPP__
#define __CORE_HPP__

#include "lexer.hpp"

typedef enum res{
    SAT,
    UNSAT
}RESULT;

class DPLL{
private:

public:
    DPLL(lexer cnf);

};

#endif
