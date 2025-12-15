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