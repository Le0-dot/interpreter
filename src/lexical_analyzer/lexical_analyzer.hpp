#pragma once

#include <iostream>
#include "../token/token.hpp"

class analyzer
{
    private:
	std::istream& input;

    public:
	analyzer(std::istream& input = std::cin);
	analyzer(analyzer& other) = default;
	analyzer(analyzer&& other) = default;
	~analyzer() = default;

	token get_token();	
};
