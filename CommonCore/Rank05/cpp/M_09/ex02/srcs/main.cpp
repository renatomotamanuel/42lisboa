#include "PmergeMe.hpp"

int main(int ac, char **av){
	if(ac < 2)
		return std::cerr << "Error: bad input" << std::endl, 1;
	if(parse(ac, av))
		return 1;
	PmergeMe merg(ac, av);
	merg.sortVec();
}