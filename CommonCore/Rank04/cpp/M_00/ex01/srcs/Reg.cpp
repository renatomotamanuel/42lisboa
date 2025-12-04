#include "../PhoneBook.hpp"

Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret)
	: _firstName(_firstName), _lastName(_lastName), _nickName(_nickName), _phoneNumber(_phoneNumber), _darkestSecret(_darkestSecret) {}

Contact::~Contact(){}

Contact& Contact::operator=(const Contact& other){
	if (this != &other){
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_nickName = other._nickName;
		this->_phoneNumber = other._phoneNumber;
		this->_darkestSecret = other._darkestSecret;
	}
	return *this;
}

std::string Contact::getFname() const{
	return (this->_firstName);
}

std::string Contact::getLname() const{
	return (this->_lastName);
}

std::string Contact::getNname() const{
	return (this->_nickName);
}

std::string Contact::getNumber() const{
	return (this->_phoneNumber);
}

void Contact::displayContact() const {
    std::cout << "First name : " << _firstName << " Last name: " << _lastName << ", Phone: " << _phoneNumber << std::endl;
}
