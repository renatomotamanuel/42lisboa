#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	Weapon *arms;
	std::string name;
public:
	HumanB(std::string newName);
	~HumanB();
	void attack();
	void setWeapon(Weapon &newArms);
};


#endif