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

#ifdef DEBUG
std::string symbol_to_str(symbols sym)
{
    switch(sym) {
	case symbols::stmt:
	    return "stmt";
	case symbols::expr:
	    return "expr";
	case symbols::expr_prime:
	    return "expr_prime";
	case symbols::term:
	    return "term";
	case symbols::term_prime:
	    return "term_prime";
	case symbols::fact:
	    return "fact";
	case symbols::num:
	    return "num";
	case symbols::plus:
	    return "plus";
	case symbols::minus:
	    return "minus";
	case symbols::mul:
	    return "mul";
	case symbols::div:
	    return "div";
	case symbols::mod:
	    return "mod";
	case symbols::lp:
	    return "lp";
	case symbols::rp:
	    return "rp";
	case symbols::plus_act:
	    return "plus_act";
	case symbols::minus_act:
	    return "minus_act";
	case symbols::mul_act:
	    return "mul_act";
	case symbols::div_act:
	    return "div_act";
	case symbols::mod_act:
	    return "mod_act";
	default:
	    return "";
    }
}
#endif
