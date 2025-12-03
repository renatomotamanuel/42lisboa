#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact array[8];
	int index;
public:
	PhoneBook();
	void addContact();
    void displayAllContact() const;
};
#endif