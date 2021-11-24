#include <variant>
#include <string>

#include "lexical_analyzer.hpp"

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9') || ch == '.';
}

analyzer::analyzer(std::istream& input, std::queue<token>& token_queue) : 
    input{input}, token_queue{token_queue}
{
    input.unsetf(std::ios_base::skipws);
}

token analyzer::get_token()
{
    char current;
    static char next = 0;
#ifdef NORMAL_ORDER
    static bool minus = false, div = false, mod = false;
    static token::number_t last = 0;
#endif

    // If next symbol was already taken
    if(next == 0) {
	input >> current;
    } else {
	current = next;
	next = 0;
    }

    // Skip spaces
    while(current == ' ')
	input >> current;

    // Assign token type
    if(is_digit(current)) {
	// Read the whole number
	std::string num{current};
	input >> next;
	while(is_digit(next)) {
	    current = next;
	    num += current;
	    input >> next;
	}
	auto number = std::stold(num);
#ifdef NORMAL_ORDER
	if(mod) {
	    number = static_cast<int>(last / number) * number;
	    mod = false;
	}
	if(div) {
	    number = 1 / number;
	    div = false;
	}
	if(minus) {
	    number = -number;
	    minus = false;
	}
	last = number;
#endif
	return token(token_types::num, number);

    } else {
	// Other cases
	token_types type;
	switch(current) {
	    case '+':
	       type = token_types::plus;
	       break;
	    case '-':
	       type = token_types::minus;
#ifdef NORMAL_ORDER
	       type = token_types::plus;
	       minus = true;
#endif
	       break;
	    case '*':
	       type = token_types::mul;
	       break;
	    case '/':
	       type = token_types::div;
#ifdef NORMAL_ORDER
	       type = token_types::mul;
	       div = true;
#endif
	       break;
	    case '%':
	       type = token_types::mod;
#ifdef NORMAL_ORDER
	       type = token_types::plus;
	       minus = true;
	       mod = true;
	       break;
#endif
	    case '(':
	       type = token_types::lp;
	       break;
	    case ')':
	       type = token_types::rp;
	       break;
	    case '\n':
	       type = token_types::eol;
	       break;
	    case '\0':
	       type = token_types::eoi;
	       break;
	    default:
	       type = token_types::unknown;
	       break;
	}
	return token(type, -1);
    }
}

token analyzer::get_line()
{
    token t{token_types::unknown, -1};
    while((t.get_type() != token_types::eol) &&
	    (t.get_type() != token_types::eoi)) {
	t = get_token();
	token_queue.push(t);
    }
    return t;
}
