#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	void	whoAmI();
	using FragTrap::takeDamage;
    using FragTrap::beRepaired;
    using ScavTrap::attack;
};


#endif