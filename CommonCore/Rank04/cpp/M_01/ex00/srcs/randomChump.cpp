#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie newChump(name);
	newChump.announce();
}