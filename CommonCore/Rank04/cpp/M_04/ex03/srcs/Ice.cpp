#include "Ice.hpp"

Ice::Ice() : AMateria("default"){
	std::cout << "Ice constructor called" << std::endl;
	_type = "default";
}

Ice::Ice(std::string type) : AMateria(type){
	std::cout << "Ice constructor called" << std::endl;
	_type = type;
}

Ice::~Ice(){
	std::cout << "Ice destructor called" << std::endl;
}
