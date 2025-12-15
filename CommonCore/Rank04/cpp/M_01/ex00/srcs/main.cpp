#include "Zombie.hpp"

int main (void)
{
	Zombie *new_z;

	new_z = newZombie("Grayson");

	randomChump("Zedrick");

	delete new_z;
	return 0;
}