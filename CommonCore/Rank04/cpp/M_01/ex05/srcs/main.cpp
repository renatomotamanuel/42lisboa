#include "Harl.hpp"

int	main (int ac, char **av)
{
	if (ac < 2)
		return std::cout << "You must give Harl a reason to complain!" << std::endl, 1;
	Harl Complainer;
	for (int i = 1; i < ac; i++)
		Complainer.complain(av[i]);
	return 0;
}