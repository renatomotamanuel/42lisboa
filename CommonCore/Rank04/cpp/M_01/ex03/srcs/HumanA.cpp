#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &newArms) : arms(newArms) {
	name = newName;
	arms = newArms;
}

HumanA::~HumanA(){
	std::cout << name << " has been DESTROYED" << std::endl;
}

void HumanA::attack(){
	std::cout << name << " attacks with their " << arms.getType() << std::endl;
}