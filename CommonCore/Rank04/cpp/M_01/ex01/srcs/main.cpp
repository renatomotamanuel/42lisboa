#include "Zombie.hpp"

int main (void)
{
	Zombie *horde;

	horde = zombieHorde(10, "Walker");
	for(int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}