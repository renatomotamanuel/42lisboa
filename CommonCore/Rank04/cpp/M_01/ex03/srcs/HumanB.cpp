#include "HumanB.hpp"

HumanB::HumanB(std::string newName){
	name = newName;
	arms = NULL;
}

HumanB::~HumanB(){
	std::cout << name << " has been DESTROYED" << std::endl;
}

void HumanB::attack(){
	if(arms)
		std::cout << name << " attacks with their " << (*arms).getType() << std::endl;
	else
		std::cout << name << " can't attack! They don't have a Weapon!" << std::endl;
}

void HumanB::setWeapon(Weapon &newArms){
	arms = &newArms;
}