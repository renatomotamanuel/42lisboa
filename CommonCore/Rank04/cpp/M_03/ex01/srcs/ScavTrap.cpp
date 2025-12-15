#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _hitPoints(100), _energyPoints(50), _attackDamage(20){
	std::cout << "Base ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _energyPoints(50), _attackDamage(20){
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
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

void ScavTrap::takeDamage(unsigned int amount){
	if(!_hitPoints){
		std::cout << "ScavTrap " << _name << " can't take damage! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is hit for " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if(_hitPoints < 0)
		_hitPoints = 0;
	if(!_hitPoints)
		std::cout << "ScavTrap " << _name << " has fainted! You should take him to a PokeCenter." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount){
	if(!_energyPoints){
		std::cout << "ScavTrap " << _name << " can't repair itself! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "ScavTrap " << _name << " can't repair itself! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " repairs itself for " << amount << " HP!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
	if(_hitPoints > 100)
		_hitPoints = 100;
	std::cout << "ScavTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
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
