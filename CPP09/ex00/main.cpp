#include "BitcoinExchange.hpp"
int main(int ac, char **av)
{
	if (ac == 2)
	{
		try{
		BitcoinExchange bit(av[1]);
		bit.check_file_print();
		}
		catch (BitcoinExchange::BadFile &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
	return 0;
}
