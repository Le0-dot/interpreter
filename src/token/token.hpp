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
	
	const token_types get_type();
	const int get_lexeme();
};
