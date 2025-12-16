#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
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
	void	displayTable(void) const;
	void	writeInfo(int idx) const;
};
#endif