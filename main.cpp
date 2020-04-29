#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

int main()
{
    std::string s("123 456");
    std::string::iterator first = s.begin(), last = s.end();
    int n1, n2;
    bool success = qi::phrase_parse(
        first,
        last,
        qi::int_ >> qi::int_,
        qi::space,
        n1, n2
    );
    if(success){
        std::cout << "OK " << n1 << ", " << n2 << std::endl;
    }
    return 0;
}