#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap constructor called" << std::endl;
	_name = name;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been DESTROYED." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if(!_energyPoints){
		std::cout << "ClapTrap " << _name << " can't attack! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "ClapTrap " << _name << " can't attack! It is already dead!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << " for " << _attackDamage << " points of damage!";
	if(_attackDamage == 0)
		std::cout << " Are you sure you're not a Magikarp?";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(!_hitPoints){
		std::cout << "ClapTrap " << _name << " can't take damage! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is hit for " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if(_hitPoints < 0)
		_hitPoints = 0;
	if(!_hitPoints)
		std::cout << "ClapTrap " << _name << " has fainted! You should take him to a PokeCenter." << std::endl;
	else
		std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if(!_energyPoints){
		std::cout << "ClapTrap " << _name << " can't repair itself! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "ClapTrap " << _name << " can't repair itself! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " HP!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
	if(_hitPoints > 10)
		_hitPoints = 10;
	std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
}
