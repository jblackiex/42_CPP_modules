#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
	std::string s = av[1];
	for(int i = 1; i < ac - 1; i++)
		if (av[i + 1])
			s = s + av[i + 1];
	int dim = s.length();
	for (int j = 0; j < dim; j++)
		s[j] = std::toupper(s[j]);
	return (std::cout << s << std::endl, 0);
}