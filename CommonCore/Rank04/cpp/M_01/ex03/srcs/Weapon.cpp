#include "Weapon.hpp"


Weapon::Weapon(std::string newType){
	type = newType;
}

Weapon::~Weapon(){
	std::cout << type << " has been DESTROYED" << std::endl;
}

const std::string& Weapon::getType() const{
	return type;
}
void Weapon::setType(std::string newType){
	this->type = newType;
}