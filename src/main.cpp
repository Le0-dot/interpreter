#include <cstdlib>
#include <iostream>
#include <queue>

#include "lexical_analyzer/lexical_analyzer.hpp"
#include "parser/parser.hpp"

token read_line(analyzer& lex_an, std::queue<token>& q)
{
    token t{token_types::unknown, -1};
    do {
	t = lex_an.get_token();
	q.push(t);
    } while((t.get_type() != token_types::eol) &&
	    (t.get_type() != token_types::eoi));
    return t;
}

void read_lines(analyzer& lex_an, parser& p, std::queue<token>& q)
{
    while(read_line(lex_an, q).get_type() != token_types::eoi) {
	std::cout << p.parse_line() << std::endl;
    }
}

int main()
{
    std::queue<token> q;
    analyzer lex_an{std::cin};
    parser p{q};

    read_lines(lex_an, p, q);
    return 0;
}
