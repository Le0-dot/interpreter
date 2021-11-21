#pragma once

#include <iostream>
#include <queue>

#include "../token/token.hpp"

class analyzer
{
    private:
	std::istream& input;
	std::queue<token>& token_queue;

    public:
	analyzer(std::istream& inputn, std::queue<token>& token_queue);
	analyzer(analyzer& other) = default;
	analyzer(analyzer&& other) = default;
	~analyzer() = default;

	token get_token();	
	token get_line();
};
