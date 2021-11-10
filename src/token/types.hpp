#pragma once 

enum class token_types {
    unknown,
    eoi, eol,
    num,
    plus, minus,
    mul, div, mod,
    pow,
    lp, rp,
};
