#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(), _name("Default"){
	ClapTrap::_name = _name + "_clap_name";
	fragGetHitPt();
	scavGetEnPt();
	fragGetAtkDmg();
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name){
	ClapTrap::_name = _name + "_clap_name";
	fragGetHitPt();
	scavGetEnPt();
	fragGetAtkDmg();
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " has been DESTROYED." << std::endl;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "ClapTrap name is: " << getName() << std::endl;
}
