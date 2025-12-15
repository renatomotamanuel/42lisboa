#include "Harl.hpp"

int	main (int ac, char **av)
{
	if (ac < 2)
		return std::cout << "You must give Harl a reason to complain!" << std::endl, 1;
	else if (ac > 2)
		return std::cout << "That's too many reasons for Harl to complain..." << std::endl, 1;
	Harl Complainer;
	Complainer.complain(av[1]);
	return 0;
}