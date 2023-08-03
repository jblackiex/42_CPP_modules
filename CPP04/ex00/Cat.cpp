#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default Constructor called, but is Cat.. so be careful" << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string name) : Animal(name) {
	std::cout << "Cat Constructor Name called, be kind" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called (it's very silent) " << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &target)
{
	if (this != &target)
		this->type = target.type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Nyaaa!" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called (miAAAHhdididvhhhhSSSssh!)" << std::endl;
}