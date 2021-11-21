#include <cmath>
#include <stdexcept>

#include "parser.hpp"
#include "../tables/parse_table/parse_table.hpp"
#include "../tables/todo_table/todo_table.hpp"

#include <iostream>
void parser::push_symbols(const std::vector<symbols>& syms)
{
    for(const auto& it: syms)
	parse_stack.push(it);
}

void print_stack(std::stack<symbols> s)
{
    std::stack<symbols> tmp;
    while(!s.empty()) {
	auto a = s.top();
	tmp.push(a);
	s.pop();
    }
    while(!tmp.empty()) {
	auto a = tmp.top();
	std::cout << symbol_to_str(a) << ' ';
	tmp.pop();
    }
    std::cout << std::endl;
}
int parser::parse_line()
{
    using namespace std::string_literals;
    // Clear value and parse stack
    value_stack = {};
    parse_stack = {};
    // Get first token
    token current = token_queue.front();
    token_queue.pop();
    // Initialize parse stack with stmt symbol
    parse_stack.push(symbols::stmt);
    // Main loop for onr line
    while(!parse_stack.empty()) {
	print_stack(parse_stack);
	std::cout << type_to_str(current.get_type()) << std::endl;
	int v1 = 0, v2 = 0, idx = -1;
	switch(parse_stack.top()) {
	    // Act cases
	    case symbols::plus_act:
		parse_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 + v2));
		break;

	    case symbols::minus_act:
		parse_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 - v2));
		break;

	    case symbols::mul_act:
		parse_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 * v2));
		break;

	    case symbols::div_act:
		parse_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 / v2));
		break;

	    case symbols::mod_act:
		parse_stack.pop();
		v2 = value_stack.top().get_lexeme();
		value_stack.pop();
		v1 = value_stack.top().get_lexeme();
		value_stack.pop();
		value_stack.push(token(token_types::num, v1 % v2));
		break;


	    // Cases for non-terminal symbols
	    case symbols::stmt:
	    case symbols::expr:
	    case symbols::expr_prime:
	    case symbols::term:
	    case symbols::term_prime:
	    case symbols::fact:
		// Get id from parser table
		idx = parse_table::get()->get_index(parse_stack.top(), current.get_type());
		parse_stack.pop();
		// Check if id is valid
		if(idx >= 0)
		    // Add symbols from todo table to the parse stack
		    push_symbols(todo_table::get()->get_row(idx));
		else
		    throw std::invalid_argument("Invalid syntaxis(non-terminal symbols)["s + 
			    symbol_to_str(parse_stack.top()) + ", "s + type_to_str(current.get_type()) + "]"s);
		break;

	    // Cases for terminal symbols
	    case symbols::num:
		parse_stack.pop();
		if(equals(symbols::num, current.get_type()))
		    value_stack.push(current);
		else
		    throw std::invalid_argument("Invalid syntaxis(terminal symbols)["s + 
			    symbol_to_str(parse_stack.top()) + ", "s + type_to_str(current.get_type()) + "]"s);
		current = token_queue.front();
		token_queue.pop();
		break;
	    case symbols::plus:
	    case symbols::minus:
	    case symbols::mul:
	    case symbols::div:
	    case symbols::mod:
	    case symbols::lp:
	    case symbols::rp:
		if(!equals(parse_stack.top(), current.get_type()))
		    throw std::invalid_argument("Invalid syntaxis(terminal symbols)["s + 
			    symbol_to_str(parse_stack.top()) + ", "s + type_to_str(current.get_type()) + "]"s);
		parse_stack.pop();
		current = token_queue.front();
		token_queue.pop();
		break;
	}
    }
    return value_stack.top().get_lexeme();
}
