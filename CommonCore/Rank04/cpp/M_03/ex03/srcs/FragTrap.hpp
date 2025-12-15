#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	highFiveGuys();
	int	fragGetAtkDmg();
	int	fragGetHitPt();
};


#endif