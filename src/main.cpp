#include <cstdlib>
#include <iostream>
#include <queue>

#include "lexical_analyzer.hpp"
#include "parser.hpp"

void read_lines(analyzer& lex_an, parser& p, std::queue<token>& q)
{
    constexpr char promt[] = ">>> ";
    std::cout << promt;
    while(lex_an.get_line().get_type() != token_types::eoi) {
	try {
	    std::cout << p.parse_line() << std::endl << promt;
	} catch(std::invalid_argument& e) {
	    std::cout << e.what() << std::endl << promt;
	}
    }
}

int main()
{
#ifdef NORMAL_ORDER
    std::cout << "NORMAL_ORDER" << std::endl;
#endif
    std::queue<token> q;
    analyzer lex_an{std::cin, q};
    parser p{q};

    read_lines(lex_an, p, q);
    return 0;
}
