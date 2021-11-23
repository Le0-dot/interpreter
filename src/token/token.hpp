#pragma once

#include <stdexcept>

#include "types.hpp"

class token
{
    public:
	using number_t = long double;

    private:
	token_types type;
	number_t lexeme;

    public:
	token(const token_types type, const number_t lexeme) :
	    type{type}, lexeme{lexeme} {};
	
	const token_types get_type();
	const number_t get_lexeme();
};
