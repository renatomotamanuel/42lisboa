#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Default Animal constructor called" << std::endl;
	_type = "";
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal has been DESTROYED" << std::endl;
}

std::string Animal::getType() const{
	return _type;
}

int Animal::makeSound() const{
	if(_type == "Cat")
		return std::cout << "Miauuuuuuuuuuuuuu" << std::endl, 0;
	else if(_type == "Dog")
		return std::cout << "AuAuAuAuAuAu" << std::endl, 0;
	return 0;
}