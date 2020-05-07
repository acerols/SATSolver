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

    bool success = qi::parse(
        iter,
        end,
        *(*(qi::char_ - qi::lit(" ")) >> qi::lit(" ")) >> (*qi::char_ | qi::space),
        resultStr
    );

    if(success){
        //Parse Comment line
        if(resultStr.at(0) == "c"){
            std::cout << "comment line" << std::endl;
        } 
        // Parse Definition line
        else if(resultStr.at(0) == "p"){
            std::cout << "definition" << std::endl;
            bool definitions = qi::phrase_parse(
                line.begin(),
                end,
                qi::lit("p") >> qi::lit("cnf") >> ((qi::int_ >> qi::int_) | (*qi::lit::ns::ch >> *ns::ch)),
                var,
                formula
            );
        }
        //Parse Bool form Line
        else if(lineCNF.size()){
            for(auto i = 0; i < lineCNF.size(); i++){
                std::cout << lineCNF.at(i) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

}
