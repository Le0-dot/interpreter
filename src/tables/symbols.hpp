#pragma once

#include <string>

#include "types.hpp"

enum class symbols {
    // Non-terminal symbols
    stmt,
    expr,
    expr_prime,
    term,
    term_prime,
    fact,

    // Terminal symbols
    num,
    plus,
    minus,
    mul,
    div,
    mod,
    lp,
    rp,

    // Actions
    plus_act,
    minus_act,
    mul_act,
    div_act,
    mod_act,
};


bool equals(symbols sym, token_types type);
bool equals(token_types type, symbols sym);

#ifdef DEBUG
std::string symbol_to_str(symbols sym);
#endif
