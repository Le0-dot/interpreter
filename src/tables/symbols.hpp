#pragma once

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
    pow,
    lp,
    rp,

    // Actions
    plus_act,
    minus_act,
    mul_act,
    div_act,
    mod_act,
    pow_act
};
