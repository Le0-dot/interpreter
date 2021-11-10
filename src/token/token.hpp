#pragma once

#include <variant>

#include "types.hpp"

class token
{
    private:
	const token_types type;
	const std::variant<int, char> lexeme;

    public:
	token(const token_types type, const std::variant<int, char> lexeme) :
	    type{type}, lexeme{lexeme} {};
	
	const token_types get_type() { return type; };
	const auto get_lexeme() { return lexeme; };
};
