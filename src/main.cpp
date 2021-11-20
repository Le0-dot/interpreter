#include <iostream>
#include <queue>
//#include "lexical_analyzer/lexical_analyzer.hpp"
#include "parser/parser.hpp"

int main()
{
    std::queue<token> q;
    q.push(token(token_types::num, 9));
    q.push(token(token_types::mod, -1));
    q.push(token(token_types::num, 2));
    q.push(token(token_types::eol, -1));
    parser p{q};
    std::cout << p.parse_line();
    return 0;
}
