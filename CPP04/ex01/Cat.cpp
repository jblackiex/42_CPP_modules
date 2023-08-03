#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default Cat Constructor called, it's brain" << std::endl;
	this->brn = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called (it's very silent) " << std::endl;
	this->brn = new Brain(*copy.brn);
	this->type = "Cat";
}

Cat &Cat::operator=(const Cat &target)
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

void	Cat::makeSound(void) const {
	std::cout << "Nyaaa!" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called (miAAAHhdididvhhhhSSSssh!), delete Brain" << std::endl;
	delete brn;
}