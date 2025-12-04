#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact array[8];
	int index;
	int _nbr;
public:
	PhoneBook();
	void addContact();
    void searchContacts() const;
};
#endif