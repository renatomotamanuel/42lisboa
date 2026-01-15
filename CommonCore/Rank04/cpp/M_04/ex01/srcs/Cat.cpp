#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Default Cat constructor called" << std::endl;
	_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat has been DESTROYED" << std::endl;
}

Cat::Cat(const Cat &other) : Animal() {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}