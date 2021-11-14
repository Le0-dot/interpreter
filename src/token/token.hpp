#pragma once

#include <stdexcept>

#include "types.hpp"

class token
{
    private:
	token_types type;
	int lexeme;

    public:
	token(const token_types type, const int lexeme) :
	    type{type}, lexeme{lexeme} {};
	
	const token_types get_type() { return type; };
	const int get_lexeme() 
	{ 
	    if(type == token_types::num)
		return lexeme;
	    else
		throw std::runtime_error("Can not access lexeme of token with no num type");
	};
};
