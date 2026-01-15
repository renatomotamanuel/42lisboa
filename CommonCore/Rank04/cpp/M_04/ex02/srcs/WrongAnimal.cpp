#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	_type = "";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal has been DESTROYED" << std::endl;
}

std::string WrongAnimal::getType() const{
	return _type;
}

int WrongAnimal::makeSound() const{
	if(_type == "WrongCat")
		return std::cout << "Wrong Miauuuuuuuuuuuuuu" << std::endl, 0;
	return 0;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}