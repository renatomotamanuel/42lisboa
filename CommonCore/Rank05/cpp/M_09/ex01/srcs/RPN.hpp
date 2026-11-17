#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstring>
# include <sstream>
# include <stack>
# include <cstdlib>
# include <cctype>
# include <list>
# include <climits>

class RPN{
private:
	std::stack<long long, std::list<long long> > _stack;
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	std::string calc(std::string input);
};

#endif

