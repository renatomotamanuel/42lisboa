#include "../PhoneBook.hpp"

int	main (void)
{
	std::string cmd;
	PhoneBook book;

	while(1)
	{
		std::cin >> cmd;
		if(std::cin.eof() )
			return (0);
		else if(cmd == "ADD")
			book.addContact();
		else if(cmd == "SEARCH")
			book.displayAllContact();
		else if(cmd == "EXIT")
			return (0);
		else
			std::cout << "Wrong usage. Try ADD or SEARCH or EXIT" << std::endl;
	}

	return 0;
}