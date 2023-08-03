#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	int	i;
	//const Animal* j = new Dog();
	//const Animal* h = new Cat();
	Animal* zoo[10];
	i = -1;
	while (++i < 5)
		zoo[i] = new(std::nothrow) Dog();
	while (i++ < 10)
		zoo[i] = new(std::nothrow) Cat();
	i = -1;
	while (++i < 5)
		delete zoo[i];
	while (i++ < 10)
		delete zoo[i];
	std::cout << std::endl;
	std::cout << std::endl;

	Dog	tmp;
	Animal j = Dog(tmp);

	Cat	tmp2;
	Animal h = Cat(tmp2);
	
	std::cout << std::endl;

	Animal *tm = new Dog(tmp);

	std::cout << std::endl;
	std::cout << std::endl;

	delete tm;
	//delete h;
	return 0;
}