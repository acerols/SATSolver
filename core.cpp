#include <iostream>
#include <cmath>
#include <vector>

#include "lexer.hpp"
#include "core.hpp"

DPLL::DPLL(clauses clauses)
{
    cls = clauses;
}

void bitvector_add(std::vector<int> &num, int add)
{
    int temp = 0;

    for(int i = 1; i < num.size(); i++){
        if(num.at(i) == 1)
            temp |= 1 << i;
    }
    temp += (add << 1);
    //std::cout << "temp num " << temp << std::endl;

    for(int i = 1; i < num.size(); i++){
        if(temp & (1 << i))
            num.at(i) = 1;
        else{
            num.at(i) = -1;
        }
    }    
}

RESULT DPLL::research()
{
    RESULT res = SAT;

    std::cout << "----------bitVector debug start----" << std::endl;

    std::vector<int> ans(cls.numVar+1, -1);
    std:: cout << ans.size() << std::endl;
    for(int i = 1; i <= (1 << cls.numVar); i++){
        for(int j = ans.size()-1; 0 < j; j--){
            std::cout << "index : " << j << " = " << ans.at(j) << " ";
        }
        std::cout << std::endl;
        bitvector_add(ans, 1);
    }

    std::cout << "----------bitVector debug end------" << std::endl;

    return res;

}