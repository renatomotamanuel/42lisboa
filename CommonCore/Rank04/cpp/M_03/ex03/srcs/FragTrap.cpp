#include "FragTrap.hpp"

FragTrap::FragTrap(){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Base FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been DESTROYED." << std::endl;
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

void FragTrap::takeDamage(unsigned int amount){
	if(!_hitPoints){
		std::cout << "FragTrap " << _name << " can't take damage! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " is hit for " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
	if(_hitPoints < 0)
		_hitPoints = 0;
	if(!_hitPoints)
		std::cout << "FragTrap " << _name << " has fainted! You should take him to a PokeCenter." << std::endl;
	else
		std::cout << "FragTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount){
	if(!_energyPoints){
		std::cout << "FragTrap " << _name << " can't repair itself! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "FragTrap " << _name << " can't repair itself! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " repairs itself for " << amount << " HP!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
	if(_hitPoints > 100)
		_hitPoints = 100;
	std::cout << "FragTrap " << _name << " now has " << _hitPoints << " HP!" << std::endl;
}

void	FragTrap::highFiveGuys(){
	if(!_energyPoints){
		std::cout << "FragTrap " << _name << " can't repair itself! It has 0 Energy Points!" << std::endl;
		return ;
	}
	else if(!_hitPoints){
		std::cout << "FragTrap " << _name << " can't repair itself! It is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " high fives (five?) guys!" << std::endl;
	_energyPoints--;
}

int	FragTrap::fragGetAtkDmg(){
	return _attackDamage;
}

int	FragTrap::fragGetHitPt(){
	return _hitPoints;
}

