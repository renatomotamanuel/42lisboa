#include "RPN.hpp"

int main(int ac, char **av){
	RPN rpn;
	std::string ret;

	if(ac != 2 || !av[1][0])
		return std::cerr << "Error: Program requires  2 arguments." << std::endl, 1;
	ret = rpn.calc(av[1]);
	if(ret.empty())
		return 1;
	std::cout << ret << std::endl;
	return 0;
}