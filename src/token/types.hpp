#pragma once 

#include <string>

enum class token_types {
    unknown,
    eoi, eol,
    num,
    plus, minus,
    mul, div, mod,
    lp, rp,
};

#ifdef DEBUG
std::string type_to_str(token_types type);
#endif
