#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	start;
	if (ac == 2)
		start.complain(av[1]);
	return 0;
}
