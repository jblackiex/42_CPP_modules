#include "RPN.hpp"
int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN reverse_polish_notation(av[1]);
		reverse_polish_notation.check_args_insert();
	}
	else
		std::cout << "Error: wrong arguments, 2 args needed." << std::endl;
	return 0;
}
