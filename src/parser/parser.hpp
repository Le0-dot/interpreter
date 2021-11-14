#pragma once

#include <stack>
#include <vector>

#include "../lexical_analyzer/lexical_analyzer.hpp"
#include "../token/token.hpp"
#include "../tables/symbols.hpp"

class parser
{
    private:
	std::stack<token> value_stack;
	std::stack<symbols> parse_stack;
	analyzer analyz;

	void push_symbols(const std::vector<symbols>& syms);

    public:
	parser(analyzer&& analyz) : analyz{analyz} {};
	~parser() = default;

	int parse_line();
};
