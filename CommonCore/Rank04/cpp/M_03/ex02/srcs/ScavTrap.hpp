#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:
	std::string _name;
	int	_hitPoints;
	int _energyPoints;
	int _attackDamage;
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	guardGate();
};


#endif