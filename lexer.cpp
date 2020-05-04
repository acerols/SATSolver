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
    int n1, n2;
    std::vector<std::string> resultStr;
    std::string::iterator iter = line.begin(), end = line.end();
    bool success = qi::phrase_parse(
        iter,
        end,
        *(qi::char_ - ' ') % ',',
        qi::space,
        resultStr
    );
    if(success){
        for(auto i = 0; i < resultStr.size(); i++){
            //std::cout << resultStr.at(i) << std::endl;
        }
    }

}
