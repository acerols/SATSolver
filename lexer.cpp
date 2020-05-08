#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include "lexer.hpp"

using namespace boost::spirit;
using namespace boost;

lexer::lexer(std::string filename){
    std::string line;
    readfile.open(filename);
    if(!readfile.is_open()){
        std::cerr << "Can not open file : " << filename << std::endl;
    }
    while(getline(readfile, line)){
        parse_line(line);
    }

    for(auto i = 0; i < CNF.size(); i++){
        for(auto j = 0; j < CNF.at(i).size(); j++){
            std::cout << CNF.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }

}

void lexer::parse_line(std::string line)
{  
    std::vector<std::string> resultStr;
    std::string::iterator iter = line.begin(), end = line.end();
    std::vector<int> lineCNF;
    //qi::rule<std::string::iterator, *qi::char_type, qi::space_type> rule = *qi::char_;
//    bool success = qi::phrase_parse(
//        iter,
//        end,
//        *qi::char_,
//        qi::space,
//        resultStr
//    );
    bool success_num = qi::phrase_parse(
        iter,
        end,
        *qi::int_,
        qi::space,
        lineCNF
    );

    bool success = qi::parse(
        iter,
        end,
        *(*(qi::char_ - qi::lit(" ")) >> qi::lit(" ")) >> (*qi::char_ | qi::space),
        resultStr
    );

    if(success){
        //Parse Comments line
        if(resultStr.at(0) == "c"){
            std::cout << "comment line" << std::endl;
        } 
        // Parse Problem line
        else if(resultStr.at(0) == "p"){
            std::cout << "definition" << std::endl;
            bool definitions = qi::phrase_parse(
                line.begin(),
                end,
                qi::lit("p") >> qi::lit("cnf") >> ((qi::int_ >> qi::int_)),
                qi::space,
                numVar,
                numLiteral
            );
            std::cout << "Number of Variable " << numVar << " : Number of Literal " << numLiteral << std::endl;
        }
        //Parse Clauses Line
        else if(lineCNF.size()){
            CNF.push_back(lineCNF);
        }
    }

}
