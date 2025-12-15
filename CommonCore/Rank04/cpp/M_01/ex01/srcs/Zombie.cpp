#include "Zombie.hpp"

Zombie::Zombie() : name("hungryBoy") {}

Zombie::Zombie(std::string name) : name(name) {}
	
Zombie::~Zombie() {
	std::cout << name << " has been DESTROYED." << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string newName){
	name = newName;
}