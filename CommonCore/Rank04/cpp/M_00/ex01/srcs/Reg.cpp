#include "../PhoneBook.hpp"

Contact::Contact(std::string _firstName, std::string _lastName, std::string _nickName, std::string _phoneNumber, std::string _darkestSecret)
	: _firstName(_firstName), _lastName(_lastName), _nickName(_nickName), _phoneNumber(_phoneNumber), _darkestSecret(_darkestSecret) {}

Contact::~Contact() {std::cout << "Contact has been destroyed." << std::endl;}

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

std::string Contact::getSecret() const{
	return (this->_darkestSecret);
}

void Contact::displayContact() const {
    std::cout << "First name : " << _firstName << " Last name: " << _lastName << ", Phone: " << _phoneNumber << std::endl;
}

void Contact::saveContact(std::string t_fname, std::string t_lname, std::string t_nname, std::string t_number, std::string t_secret){
	_firstName = t_fname;
	_lastName = t_lname;
	_nickName = t_nname;
	_phoneNumber = t_number;
	_darkestSecret = t_secret;
}
