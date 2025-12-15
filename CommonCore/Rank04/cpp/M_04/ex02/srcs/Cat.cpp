#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Default Cat constructor called" << std::endl;
	_type = "Cat";
	_think = _think->newBrain();
}

Cat::~Cat() {
	std::cout << "Cat has been DESTROYED" << std::endl;
	delete _think;
}

int Cat::makeSound() const{
	return std::cout << "Miauuuuuuuuuuuuuu" << std::endl, 0;
}