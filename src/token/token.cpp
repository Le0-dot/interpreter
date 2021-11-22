#include "token.hpp"

const token_types token::get_type() { return type; };;

const int token::get_lexeme()
{
    if(type == token_types::num)
	return lexeme;
    else
	throw std::runtime_error("Can not access lexeme of token with no num type");
}
