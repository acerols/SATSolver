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

RESULT DPLL::FullSearch()
{
    RESULT res = SAT;

    std::vector<int> ans(cls.numVar+1, -1);
    /*
    for(auto i = 0; i < cls.CNF.size(); i++){
        std::cout << "Literal=" << i << " : ";
        for(auto j = 1; j < cls.CNF.at(i).size(); j++){
            std::cout << j << "=" << cls.CNF.at(i).at(j) << ", ";
        }
        std::cout << std::endl;
    }
    */
    //index=i番目の解
    for(int i = 1; i <= (1 << cls.numVar); i++){

        int j;
        bool solved = true;
        //index=j番目のcls
        for(j = 0; j < cls.CNF.size(); j++){
            int k;
            //j番目のclsのk番目の論理変数について検証
            for(k = 1; k < cls.CNF.at(j).size(); k++){
                //j番目のclsのk番目の論理変数について記述がなければskip
                if(cls.CNF.at(j).at(k) == 0){
                    continue;
                }
                //解がindex=kのclsを満たすならそのclsは真である
                else if(ans.at(k) == cls.CNF.at(j).at(k)){
                    break;
                }
            }

            //解がindex=kのclsで真であるためk+1のclsを満たすか検証
            if(k != cls.CNF.at(j).size()){
                continue;
            }
            //idenx=iの解がindex=kのclsを満たさないためi+1の解で検証
            else{
                solved = false;
                break;
            }
            res = UNSAT;
        }
        //解がすべてのclsを満たすため，示されたCNFの解はindex=i
        if(j == cls.CNF.size() && solved == true){

            for(int j = ans.size()-1; 0 < j; j--){
                std::cout << "index : " << j << " = " << ans.at(j) << " ";
            }
            std::cout << std::endl;

            std::cout << "Solved! done!" << std::endl;
            return SAT;
        }
        //解がすべてのclsを満たさなかったため解をインクリメント
        bitvector_add(ans, 1);
    }

    return UNSAT;

}