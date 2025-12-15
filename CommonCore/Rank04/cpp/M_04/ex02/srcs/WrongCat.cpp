#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "Default WrongCat constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat has been DESTROYED" << std::endl;
}