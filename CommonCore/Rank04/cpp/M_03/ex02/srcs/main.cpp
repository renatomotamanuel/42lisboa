#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {

	ClapTrap Mecha1("Bob");
	ClapTrap Mecha2("Joe");
	ScavTrap Mecha3("Cole");
	FragTrap Mecha4("Zoro");

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
	Mecha4.attack("Bob");
	Mecha4.takeDamage(10);
	Mecha4.beRepaired(10);
	Mecha4.highFiveGuys();
	return 0;
}