#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "Base FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name = "Default";
}

FragTrap::FragTrap(std::string name) : ClapTrap(){
	std::cout << "FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name = name;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been DESTROYED." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	return *this;
}

void FragTrap::attack(const std::string& target){
	if(!_energyPoints){
		std::cout << "FragTrap " << _name << " can't attack! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "FragTrap " << _name << " can't attack! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << " for " << _attackDamage << " points of damage!";
	_energyPoints--;
	if(_attackDamage == 0)
		std::cout << " Are you sure you're not a Magikarp?";
	std::cout << std::endl;
}

void	FragTrap::highFiveGuys(){
	if(!_energyPoints){
		std::cout << "FragTrap " << _name << " can't high five! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "FragTrap " << _name << " can't high five! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " high fives (five?) guys!" << std::endl;
	_energyPoints--;
}
