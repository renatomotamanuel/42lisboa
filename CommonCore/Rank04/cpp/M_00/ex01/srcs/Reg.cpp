#include "../PhoneBook.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string number)
	: first_name(first_name), last_name(last_name), number(number) {}

Contact::~Contact(){}

Contact& Contact::operator=(const Contact& other){
	if (this != &other){
		this->first_name = other.first_name;
		this->last_name = other.last_name;
		this->number = other.number;
	}
	return *this;
}

void Contact::displayContact() const {
    std::cout << "First name :" << first_name << "Last name: " << last_name << ", Phone: " << number << std::endl;
}
