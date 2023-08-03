#include "Zombie.h"

int	main()
{
	Zombie  *horde = zombieHorde(10, "horde");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}