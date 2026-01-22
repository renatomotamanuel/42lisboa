#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
	std::cout << "AMateria constructor called" << std::endl;
	_type = type;
}

std::string const & AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter& target){

}

AMateria::~AMateria(){
	std::cout << "AMateria destructor called" << std::endl;
}