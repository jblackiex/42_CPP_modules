#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Default Constructor called, but is Dog.. so be CAREFUL!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string name) : Animal(name) {
	std::cout << "Dog Constructor Name called (this is a surprise)" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called (i'm not Dolly)" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &target)
{
	if (this != &target)
		this->type = target.type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Bau!" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called (hiuhuhHU!!)" << std::endl;
}