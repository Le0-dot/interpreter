#include <variant>
#include <string>

#include "lexical_analyzer.hpp"

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

analyzer::analyzer(std::istream& input) : input{input}
{
    input.unsetf(std::ios_base::skipws);
}

token analyzer::get_token()
{
    char current;
    static char next = 0;

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
	std::string num = &current;
	input >> next;
	while(is_digit(next)) {
	    current = next;
	    num += current;
	    input >> next;
	}
	return token(token_types::num, std::stoi(num));
    } else {
	// Other cases
	token_types type;
	switch(current) {
	    case '+':
	       type = token_types::plus;
	       break;
	    case '-':
	       type = token_types::minus;
	       break;
	    case '*':
	       input >> next;
	       if(next == '*')
		   type = token_types::pow;
	       else
		   type = token_types::mul;
	       input >> next;
	       break;
	    case '/':
	       type = token_types::div;
	       break;
	    case '%':
	       type = token_types::mod;
	       break;
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
