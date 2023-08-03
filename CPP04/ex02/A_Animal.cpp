#include "A_Animal.hpp"

A_Animal::A_Animal(std::string Name) {
	std::cout << "A_Animal Constructor Name called" << std::endl;
	this->type = Name;
}

A_Animal::A_Animal() {
	std::cout << "Default Constructor A_Animal called" << std::endl;
	this->type = "";
}

A_Animal::A_Animal(const A_Animal &toCopy) {
	std::cout << "A_Animal copy constructor called" << std::endl;
	*this = toCopy;
}

const std::string&	A_Animal::getType(void) const{
	return (this->type);
}

void	A_Animal::makeSound(void) const{
	std::cout << "ahsjhdjhajshds42miaoooBAU!" << std::endl;
}

A_Animal&	A_Animal::operator=(const A_Animal&ref) {
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}