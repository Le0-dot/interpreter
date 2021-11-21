#include "parse_table.hpp"

parse_table* parse_table::instance = nullptr;

parse_table::parse_table()
{
    std::map<token_types, int> temp = {
	{token_types::num, 0},
	{token_types::plus, -1},
	{token_types::minus, -1},
	{token_types::mul, -1},
	{token_types::div, -1},
	{token_types::mod, -1},
	{token_types::lp, 0},
	{token_types::rp, -1},
	{token_types::eol, 10},
	{token_types::eoi, 10},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::stmt, std::move(temp));

    temp = {
	{token_types::num, 1},
	{token_types::plus, -1},
	{token_types::minus, -1},
	{token_types::mul, -1},
	{token_types::div, -1},
	{token_types::mod, -1},
	{token_types::lp, 1},
	{token_types::rp, -1},
	{token_types::eol, -1},
	{token_types::eoi, -1},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::expr, std::move(temp));
    
    temp = {
	{token_types::num, 10},
	{token_types::plus, 2},
	{token_types::minus, 3},
	{token_types::mul, 10},
	{token_types::div, 10},
	{token_types::mod, 10},
	{token_types::lp, 10},
	{token_types::rp, 10},
	{token_types::eol, 10},
	{token_types::eoi, 10},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::expr_prime, std::move(temp));

    temp = {
	{token_types::num, 4},
	{token_types::plus, -1},
	{token_types::minus, -1},
	{token_types::mul, -1},
	{token_types::div, -1},
	{token_types::mod, -1},
	{token_types::lp, 4},
	{token_types::rp, -1},
	{token_types::eol, -1},
	{token_types::eoi, -1},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::term, std::move(temp));

    temp = {
	{token_types::num, 10},
	{token_types::plus, 10},
	{token_types::minus, 10},
	{token_types::mul, 5},
	{token_types::div, 6},
	{token_types::mod, 7},
	{token_types::lp, 10},
	{token_types::rp, 10},
	{token_types::eol, 10},
	{token_types::eoi, 10},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::term_prime, std::move(temp));

    temp = {
	{token_types::num, 8},
	{token_types::plus, -1},
	{token_types::minus, -1},
	{token_types::mul, -1},
	{token_types::div, -1},
	{token_types::mod, -1},
	{token_types::lp, 9},
	{token_types::rp, -1},
	{token_types::eol, -1},
	{token_types::eoi, -1},
	{token_types::unknown, -1},
    };
    table.emplace(symbols::fact, std::move(temp));
}

parse_table* parse_table::get()
{
    if(!instance)
	instance = new parse_table{};
    return instance;
}

int parse_table::get_index(symbols sym, token_types token)
{
    return table.at(sym).at(token);
}
