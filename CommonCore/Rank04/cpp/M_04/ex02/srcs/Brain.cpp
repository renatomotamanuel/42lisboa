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

Brain::Brain(const Brain &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		for(int i = 0; i < 100; i++){
			if (this->_ideas[i] != other._ideas[i])
				this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}