#pragma once

#include <stack>
#include <vector>
#include <queue>

#include "../token/token.hpp"
#include "../tables/symbols.hpp"

class parser
{
    private:
	std::stack<token> value_stack;
	std::stack<symbols> parse_stack;
	std::queue<token>& token_queue;

	void push_symbols(const std::vector<symbols>& syms);

    public:
	parser(std::queue<token>& token_queue) : token_queue{token_queue},
	    value_stack{}, parse_stack{} {};
	~parser() = default;

	int parse_line();
};
