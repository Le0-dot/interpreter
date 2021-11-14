#include "symbols.hpp"


bool equals(symbols sym, token_types type)
{
    if(sym == symbols::num && type == token_types::num)
	return true;
    if(sym == symbols::plus && type == token_types::plus)
	return true;
    if(sym == symbols::minus && type == token_types::minus)
	return true;
    if(sym == symbols::mul && type == token_types::mul)
	return true;
    if(sym == symbols::div && type == token_types::div)
	return true;
    if(sym == symbols::mod && type == token_types::mod)
	return true;
    if(sym == symbols::pow && type == token_types::pow)
	return true;
    if(sym == symbols::lp && type == token_types::lp)
	return true;
    if(sym == symbols::rp && type == token_types::rp)
	return true;
    return false;
}

bool equals(token_types type, symbols sym)
{
    return equals(sym, type);
}
