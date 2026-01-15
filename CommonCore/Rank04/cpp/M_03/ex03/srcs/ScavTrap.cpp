#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_name = "Default";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(){
	std::cout << "Base ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_name = name;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been DESTROYED." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if(!_energyPoints){
		std::cout << "ScavTrap " << _name << " can't attack! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "ScavTrap " << _name << " can't attack! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << " for " << _attackDamage << " points of damage!";
	_energyPoints--;
	if(_attackDamage == 0)
		std::cout << " Are you sure you're not a Magikarp?";
	std::cout << std::endl;
}

void	ScavTrap::guardGate(){
	if(!_energyPoints){
		std::cout << "ScavTrap " << _name << " can't repair itself! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "ScavTrap " << _name << " can't repair itself! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
	_energyPoints--;
}
