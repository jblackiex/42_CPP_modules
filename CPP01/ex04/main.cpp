#include "main.hpp"

int	main(int ac, char **av)
{
	std::ifstream	file; // sola lettura
	std::ofstream	outputfile; // scrittura
	std::string		tmp;
	size_t			i;

	if (ac != 4 || !av[2][0] || !av[3][0] || !av[1][0])
		return (std::cout << "Error, too few parameters.. orrr NULL character found" << std::endl, 1);
	std::string s1 = av[2];
	std::string s2 = av[3];
	file.open(av[1]);
	tmp = av[1] + std::string(".replace"); // cast from str to string
	outputfile.open(tmp.c_str()); // cast from string to str
	if (file.fail() || outputfile.fail())
		return (std::cout << "Error opening file.." << std::endl, 1);
	while (getline(file, tmp))
	{
		size_t pos_s1 = tmp.find(av[2], 0);
		i = 0;
		while (pos_s1 != std::string::npos)
		{
			tmp.erase(pos_s1, s1.size());
			tmp.insert(pos_s1, s2);
			i = pos_s1;
			pos_s1 = tmp.find(av[2], i + s2.size());
		}
		outputfile << tmp.append("\n");
	}
	return 0;
}