#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	guardGate();
	int	scavGetEnPt();
};


#endif