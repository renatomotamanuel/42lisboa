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
	array[index].saveContact(t_fname, t_lname, t_nname, t_number, t_secret);
    index++;
	if (_nbr < 8)
		_nbr++;
}

void	writeTop(void){
	int ext = 0;
	for(int var = 0; var < 44; var++){
		if ((var - ext) % 10 == 0){
			std::cout << '|';
			ext++;
			std::cout << "‾";
			var++;
		}
		else
			std::cout << "‾";
	}
	std::cout << '|' << std::endl;
}

void	writeBot(void){
	for(int var = 0; var < 4; var++)
		std::cout << '|' << std::setw(10) << std::setfill('_') << "";
	std::cout  << '|' << std::endl;
}

std::string	truncName(std::string str){
	if (str.length() > 10){
		str = str.substr(0, 9);
		str += '.';
	}
	return str;
}

void	PhoneBook::writeInfo(int idx) const{
	if (idx == -1){
		std::cout << '|' << std::setw(10) << std::setfill(' ') << "Index" << std::setw(0) << '|' 
		<< std::setw(10) << std::setfill(' ') << "F. Name" << std::setw(0) << '|' 
		<< std::setw(10) << std::setfill(' ') << "L. Name" << std::setw(0) << '|' 
		<< std::setw(10) << std::setfill(' ') << "Nickname" << std::setw(0) << '|'<< std::endl;
		return ;
	}
	std::cout << '|' << std::setw(9) << std::setfill(' ') << idx + 1 << '.' << std::setw(0) << '|' 
	<< std::setw(10) << std::setfill(' ') << truncName(array[idx].getFname()) << std::setw(0) << '|' 
	<< std::setw(10) << std::setfill(' ') << truncName(array[idx].getLname()) << std::setw(0) << '|' 
	<< std::setw(10) << std::setfill(' ') << truncName(array[idx].getNname()) << std::setw(0) << '|'<< std::endl;
}

void	PhoneBook::displayTable(void) const{
	for(int var = 0; var < _nbr + 1; var++){
		writeTop();
		writeInfo(var - 1);
		writeBot();
	}
}
void PhoneBook::searchContacts() const {
	std::string str;
	if(_nbr == 0){
		std::cout << "No contacts added yet. First use the ADD command." << std::endl;
		return ;
	}
	displayTable();
	int bnbr;
	std::cout << "Insert the index of the contact you're trying to search:";
	while(1){
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
	bnbr--;
	std::cout << "First name: " << array[bnbr].getFname() << std::endl;
	std::cout << "Last name: " << array[bnbr].getLname() << std::endl;
	std::cout << "Nickname: " << array[bnbr].getNname() << std::endl;
	std::cout << "Phone number: " << array[bnbr].getNumber() << std::endl;
	std::cout << "Darkest secret: " << array[bnbr].getSecret() << std::endl;
}