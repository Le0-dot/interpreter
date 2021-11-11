#pragma once

#include <map>
#include <memory>

#include "../symbols.hpp"
#include "../../token/types.hpp"

class parse_table
{
    private:
	std::map<symbols, std::map<token_types, int>> table;
	static parse_table* instance;
    
	parse_table();

    public:
	static parse_table* get();
	int get_index(symbols sym, token_types token);
};
