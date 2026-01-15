#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Default Dog constructor called" << std::endl;
	_type = "Dog";
	_think = _think->newBrain();
}

Dog::~Dog() {
	std::cout << "Dog has been DESTROYED" << std::endl;
	delete _think;
}

int Dog::makeSound() const{
	return std::cout << "AuAuAuAuAuAu" << std::endl, 0;
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