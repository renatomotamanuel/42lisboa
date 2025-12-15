#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Default Dog constructor called" << std::endl;
	_type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog has been DESTROYED" << std::endl;
}