#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* ii = new WrongCat();
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound(); //will output the Wrongcat sound OR Same sound as WrongAnimal
	meta2->makeSound(); // Sound of WrongAnimal

	delete meta2;
	delete ii;

	return 0 ;
}