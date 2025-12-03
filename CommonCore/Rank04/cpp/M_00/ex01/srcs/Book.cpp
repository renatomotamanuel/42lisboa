#include "../PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact() {
    std::string t_fname;
    std::string t_lname;
    std::string t_number;
	if (index > 7)
        index = 0;
	std::cout << "Insert first name:";
	std::cin >> t_fname;
	std::cout << "Insert last name:";
	std::cin >> t_lname;
	std::cout << "Insert number:";
	std::cin >> t_number;
    array[index] = Contact(t_fname, t_lname, t_number);
    index++;
}

void PhoneBook::displayAllContact() const {
    for (int i = 0; i < index; i++) {
        std::cout << "Contact " << i + 1 << ": ";
        array[i].displayContact();
    }
}