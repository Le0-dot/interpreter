#include <iostream>

#include "lexical_analyzer/lexical_analyzer.hpp"
#include "parser/parser.hpp"

int main()
{
    analyzer a{std::cin};
    parser p{std::move(a)};
    std::cout << p.parse_line();
    return 0;
}
