#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain has been DESTROYED" << std::endl;
}


Brain *Brain::newBrain(){
	return new Brain();
}