#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	Weapon &arms;
	std::string name;
public:
	HumanA(std::string newName, Weapon &newArms);
	~HumanA();
	void attack();
};


#endif