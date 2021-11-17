#include "todo_table.hpp"
#include <vector>

todo_table* todo_table::instance = nullptr;
#include <iostream>
todo_table::todo_table()
{
    std::vector<symbols> temp = {symbols::expr};
    table[0] = std::move(temp);
    
    temp = {symbols::expr_prime, symbols::term};
    table[1] = std::move(temp);
    
    temp = {symbols::plus_act, symbols::expr_prime, symbols::term, symbols::plus};
    table[2] = std::move(temp);
    
    temp = {symbols::minus_act, symbols::expr_prime, symbols::term, symbols::minus};
    table[3] = std::move(temp);
    
    temp = {symbols::term_prime, symbols::fact};
    table[4] = std::move(temp);
    
    temp = {symbols::mul_act, symbols::term_prime, symbols::fact, symbols::mul};
    table[5] = std::move(temp);
    
    temp = {symbols::div_act, symbols::term_prime, symbols::fact, symbols::div};
    table[6] = std::move(temp);
    
    temp = {symbols::mod_act, symbols::term_prime, symbols::fact, symbols::mod};
    table[7] = std::move(temp);
    
    temp = {symbols::num};
    table[8] = std::move(temp);
    
    temp = {symbols::pow_act, symbols::term_prime, symbols::fact, symbols::pow};
    table[9] = std::move(temp);
    
    temp = {symbols::lp, symbols::expr, symbols::rp};
    table[10] = std::move(temp);
    
    temp = {};
    table[11] = std::move(temp);
}

todo_table* todo_table::get()
{
    if(!instance)
	instance = new todo_table{};
    return instance;
}

std::vector<symbols>& todo_table::get_row(int idx)
{
    return table.at(idx);
}
