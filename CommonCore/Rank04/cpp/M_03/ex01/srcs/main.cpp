#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

	ClapTrap Mecha1("Bob");
	ClapTrap Mecha2("Joe");
	ScavTrap Mecha3("Cole");

	Mecha1.attack("Joe");
	Mecha2.takeDamage(0);
	Mecha1.takeDamage(7);
	Mecha1.beRepaired(3);
	Mecha1.beRepaired(6);
	Mecha1.takeDamage(12);
	Mecha1.takeDamage(12);
	Mecha1.beRepaired(6);
	Mecha1.attack("Joe");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha2.attack("Bob");
	Mecha3.attack("Joe");
	Mecha3.takeDamage(10);
	Mecha3.beRepaired(10);
	Mecha3.guardGate();
	
	return 0;
}