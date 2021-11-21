#include "types.hpp"

#ifdef DEBUG
std::string type_to_str(token_types type)
{
    switch(type) {
	case token_types::unknown:
	    return "unknown";
	case token_types::eoi:
	    return "eoi";
	case token_types::eol:
	    return "eol";
	case token_types::num:
	    return "num";
	case token_types::plus:
	    return "plus";
	case token_types::minus:
	    return "minus";
	case token_types::mul:
	    return "mul";
	case token_types::div:
	    return "div";
	case token_types::mod:
	    return "mod";
	case token_types::lp:
	    return "lp";
	case token_types::rp:
	    return "rp";
	default:
	    return "";
    }
}
#endif
