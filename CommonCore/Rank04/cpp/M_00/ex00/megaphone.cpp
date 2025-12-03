#include <iostream>

int	main (int ac, char **av)
{
	int	var = 1, var2 = 0;

	if(ac == 1)
		return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0;
	while(av[var])
	{
		var2 = 0;
		while(av[var][var2])
		{
			if(av[var][var2] >= 97 && av[var][var2] <= 122)
				av[var][var2] -= 32;
			var2++;
		}
		std::cout << av[var];
		var++;
	}
	std::cout << std::endl;
	return 0;
}