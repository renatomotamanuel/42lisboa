#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstring>
# include <sstream>
# include <stack>
# include <cstdlib>
# include <cctype>

class RPN{
private:
	std::stack<int> _stack;
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	std::string calc(std::string input);
};

#endif

