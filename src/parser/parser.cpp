#include <cmath>
#include <stdexcept>

#include "parser.hpp"
#include "../tables/parse_table/parse_table.hpp"
#include "../tables/todo_table/todo_table.hpp"

void parser::push_symbols(const std::vector<symbols>& syms)
{
    for(const auto& it: syms)
	parse_stack.push(it);
}

int parser::parse_line()
{
    // Clear value and parse stack
    value_stack = {};
    parse_stack = {};
    // Get first token
    token current = analyz.get_token();
    // Initialize parse stack with stmt symbol
    parse_stack.push(symbols::stmt);
    // Main loop for onr line
    while(!parse_stack.empty()) {
	int v1 = 0, v2 = 0, idx = -1;
	switch(parse_stack.top()) {
	    // Act cases
	    case symbols::plus_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 + v2));
		break;

	    case symbols::minus_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 - v2));
		break;

	    case symbols::mul_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 * v2));
		break;

	    case symbols::div_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 / v2));
		break;

	    case symbols::mod_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 % v2));
		break;

	    case symbols::pow_act:
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, static_cast<int>(std::pow(v1, v2))));
		break;


	    // Cases for non-terminal symbols
	    case symbols::stmt:
	    case symbols::expr:
	    case symbols::expr_prime:
	    case symbols::term:
	    case symbols::term_prime:
	    case symbols::fact:
		// Get id from parser table
		idx = parse_table::get()->get_index(parse_stack.top(), value_stack.top().get_type());
		// Check if id is valid
		if(idx >= 0)
		    // Add symbols from todo table to the parse stack
		    push_symbols(todo_table::get()->get_row(idx));
		else
		    throw std::invalid_argument("Invalid syntaxis");
		break;

	    // Cases for terminal symbols
	    case symbols::num:
		parse_stack.pop();
		if(equals(symbols::num, current.get_type()))
		    value_stack.push(current);
		else
		    throw std::invalid_argument("Invalid syntaxis");
		current = analyz.get_token();
		break;
	    case symbols::plus:
	    case symbols::minus:
	    case symbols::mul:
	    case symbols::div:
	    case symbols::mod:
	    case symbols::pow:
	    case symbols::lp:
	    case symbols::rp:
		if(!equals(parse_stack.top(), current.get_type()))
		    throw std::invalid_argument("Invalid syntaxis");
		parse_stack.pop();
		current = analyz.get_token();
		break;
	}
    }
    return value_stack.top().get_lexeme();
}
