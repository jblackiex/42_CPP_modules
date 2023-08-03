#include <iostream>
#include <cctype>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = *stringPTR;

	std::cout << "brain_address: "<< &brain << std::endl << "stringPTR_address: " << stringPTR << std::endl << "stringREF_address: " << &stringREF << std::endl << std::endl;
	std::cout << "brain_value: "<< brain << std::endl << "stringPTR_value: " << *stringPTR << std::endl << "stringREF_value: " << stringREF << std::endl;
	return 0;
}