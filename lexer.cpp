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

    if(lineCNF.size()){
        std::cout << "NUM OK" << std::endl;
        for(auto i = 0; i < lineCNF.size(); i++){
            std::cout << lineCNF.at(i) << " ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "NUM NO" << std::endl;
    }

    bool success = qi::parse(
        iter,
        end,
        *(*(qi::char_ - qi::lit(" ")) >> qi::lit(" ")) >> (*qi::char_ | qi::space),
        resultStr
    );

    if(success){
        if(resultStr.at(0) == "c"){
            std::cout << "comment line" << std::endl;
        } 
        else if(resultStr.at(0) == "p"){
            std::cout << "definition" << std::endl;
        }
        else if(lineCNF.size());
        for(auto i = 0; i < resultStr.size(); i++){
            std::cout << resultStr.at(i) << " ";
        }
        std::cout << std::endl;
    }

}
