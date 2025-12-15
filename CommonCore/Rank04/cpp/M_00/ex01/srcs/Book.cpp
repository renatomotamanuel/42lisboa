#include "../PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), _nbr(0) {}

void PhoneBook::addContact() {
    std::string t_fname;
    std::string t_lname;
    std::string t_nname;
    std::string t_number;
    std::string t_secret;
	if (index > 7)
        index = 0;
	std::cout << "Insert first name:";
	std::cin >> t_fname;
	if(std::cin.eof())
			return ;
	std::cout << "Insert last name:";
	std::cin >> t_lname;
	if(std::cin.eof())
			return ;
	std::cout << "Insert nickname:";
	std::cin >> t_nname;
	if(std::cin.eof())
			return ;
	int i;
	while(1)
	{
		i = 0;
		std::cout << "Insert phone number:";
		if(std::cin.eof())
			return ;
		std::cin >> t_number;
		while(t_number[i])
		{
			if (!isdigit(t_number[i]))
			{
				std::cout << "Phone number may only contain digits." << std::endl;
				break ;
			}
			i++;
		}
		if(!t_number[i])
			break ;
	}
	std::cout << "Insert darkest secret:";
	std::cin >> t_secret;
    if(std::cin.eof())
			return ;
	array[index] = Contact(t_fname, t_lname, t_nname, t_number, t_secret);
    index++;
	if (_nbr < 8)
		_nbr++;
}

void PhoneBook::searchContacts() const {
    int var = 0;
	int var2 = 0;
	int i = 0;
	std::string str;
	if(_nbr == 0)
	{
		std::cout << "No contacts added yet. First use the ADD command." << std::endl;
		return ;
	}
	while(var < (_nbr * 3) + 3)
	{
		var2 = 0;
		while(var2 < 45)
		{
			if (var2 == 0 || var2 == 11 || var2 == 22 || var2 == 33 || var2 == 44)
				std::cout << '|';
			else if (var == 0 || var == 3 || var == 6 || var == 9 || var == 12 || var == 15 || var == 18 || var == 21 || var == 24)
				std::cout << "‾";
			else if (var == 2 || var == 5 || var == 8 || var == 11 || var == 14 || var == 17 || var == 20 || var == 23 || var == 26)
				std::cout << '_';
			else if (var == 1)
			{
				if(var2 == 1)
				{
					std::cout << "First Name";
					var2 = 10;
				}
				else if (var2 == 12)
				{
					std::cout << "Last  Name";
					var2 = 21;
				}
				else if (var2 == 23)
				{
					std::cout << " Nickname ";
					var2 = 32;
				}
				else if (var2 == 34)
				{
					std::cout << "Phone  nbr";
					var2 = 43;
				}
			}
			else if(var == (i + 1) * 3 + 1)
			{
				if (var2 == 1)
				{
					str = array[i].getFname();
					std::cout << i + 1 << ". ";
					if (str.length() > 7)
					{
						str = str.substr(0, 6);
						std::cout << str << '.';
					}
					else
					{
						int j = 7 - str.length();
						while(j > 0)
						{
							std::cout << ' ';
							j--;
						}
						std::cout << str;
					}
					var2 = 10;
				}
				else if (var2 == 12)
				{
					str = array[i].getLname();
					if (str.length() > 10)
					{
						str = str.substr(0, 9);
						std::cout << str << '.';
					}
					else
					{
						int j = 10 - str.length();
						while(j > 0)
						{
							std::cout << ' ';
							j--;
						}
						std::cout << str;
					}
					var2 = 21;
				}
				else if (var2 == 23)
				{
					str = array[i].getNname();
					if (str.length() > 10)
					{
						str = str.substr(0, 9);
						std::cout << str << '.';
					}
					else
					{
						int j = 10 - str.length();
						while(j > 0)
						{
							std::cout << ' ';
							j--;
						}
						std::cout << str;
					}
					var2 = 32;
				}
				else if (var2 == 34)
				{
					str = array[i].getNumber();
					if (str.length() > 10)
					{
						str = str.substr(0, 9);
						std::cout << str << '.';
					}
					else
					{
						int j = 10 - str.length();
						while(j > 0)
						{
							std::cout << ' ';
							j--;
						}
						std::cout << str;
					}
					var2 = 43;
					i++;
				}
			}
			else
				std::cout << ' ';
			var2++;
		}
		std::cout << std::endl;
		var++;
	}
	int bnbr;
	std::cout << "Insert the index of the contact you're trying to search:";
	while(1)
	{
		std::cin >> str;
		if(std::cin.eof())
			exit (0);
		bnbr = std::atoi(str.c_str());
		if(bnbr >= _nbr + 1 || bnbr < 1)
			std::cout << "Wrong usage. Try inserting only a digit of a valid contact " << std::endl;
		else
			break ;
		std::cout << "Try again:";
	}
	var = 0;
	bnbr--;
	std::cout << "First name: " << array[bnbr].getFname() << std::endl;
	std::cout << "Last name: " << array[bnbr].getLname() << std::endl;
	std::cout << "Nickname: " << array[bnbr].getNname() << std::endl;
	std::cout << "Phone number: " << array[bnbr].getNumber() << std::endl;
	std::cout << "Darkest secret: " << array[bnbr].getSecret() << std::endl;
}