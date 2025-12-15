#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Default Cat constructor called" << std::endl;
	_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat has been DESTROYED" << std::endl;
}