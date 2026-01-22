#include "Cure.hpp"

Cure::Cure() : AMateria("default"){
	std::cout << "Cure constructor called" << std::endl;
	_type = "default";
}

Cure::Cure(std::string type) : AMateria(type){
	std::cout << "Cure constructor called" << std::endl;
	_type = type;
}

Cure::~Cure(){
	std::cout << "Cure destructor called" << std::endl;
}
