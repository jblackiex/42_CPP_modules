#include "Zombie.h"

int	main()
{
	for (int i = 0; i < 10; i++)
		randomChump("ZombieStack");
    std::cout << std::endl;
    Zombie  *Zomb = newZombie("ZombieHeap");
    Zomb->announce();
    delete Zomb;
    return 0;
}