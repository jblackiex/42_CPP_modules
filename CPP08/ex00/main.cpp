#include "easyfind.hpp"

int main(void)
{
	std::vector<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	try {
	easyfind(numbers, 33);
	}
	catch (Vector::ElementNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}

	try {
	numbers.insert(numbers.begin(), 33);
	easyfind(numbers, 33);
	}
	catch (Vector::ElementNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "---------------------" << std::endl;
	std::list<int> list;
	list.push_back('1');
	list.push_back(0);
	list.push_back('3');

	try {
	easyfind(list, 0);
	}
	catch (Vector::ElementNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	easyfind(list, 48);
	}
	catch (Vector::ElementNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	easyfind(list, 51);
	}
	catch (Vector::ElementNotFound &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}


// // Inserisci una sequenza di elementi alla posizione 2
// myVector.insert(it, {20, 30, 40});