#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Default Dog Constructor called, it's brain" << std::endl;
	this->brn = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called (i'm not Dolly)" << std::endl;
	this->brn = new Brain(*copy.brn);
	this->type = "Dog";
}

Dog &Dog::operator=(const Dog &target)
{
	if (this != &target)
	{
		this->type = target.type;
		if (brn)
			delete brn;
		this->brn = new Brain(*target.brn);
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Bau!" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called (hiuhuhHU!!), delete Brain" << std::endl;
	delete brn;
}