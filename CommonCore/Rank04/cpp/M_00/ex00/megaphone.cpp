#include <iostream>

int	main (int ac, char **av)
{
	if(ac == 1)
		return std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0;
	for(int var = 0; av[var]; var++){
		std::string str = av[var];
		for(int var2 = 0; str[var2]; var2++)
			str[var2] = std::toupper(str[var2]);
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}