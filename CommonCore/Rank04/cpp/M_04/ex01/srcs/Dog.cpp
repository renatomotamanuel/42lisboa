#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Default Dog constructor called" << std::endl;
	_type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog has been DESTROYED" << std::endl;
}

Dog::Dog(const Dog &other) : Animal() {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}