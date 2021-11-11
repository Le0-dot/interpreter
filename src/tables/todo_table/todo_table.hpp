#pragma once

#include <array>
#include <vector>

#include "../symbols.hpp"

class todo_table
{
    private:
	std::array<std::vector<symbols>, 11> table;
	static todo_table* instance;

	todo_table();

    public:
	todo_table* get();
	std::vector<symbols>& get_row(int idx);
};
