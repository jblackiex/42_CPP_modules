#include "Animal.hpp"

Animal::Animal(std::string Name) {
	std::cout << "Animal Constructor Name called" << std::endl;
	this->type = Name;
}
Animal::Animal() {
	std::cout << "Default Constructor Animal called" << std::endl;
	this->type = "";
}

Animal::Animal(const Animal &toCopy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = toCopy;
}

const std::string&	Animal::getType(void) const{
	return (this->type);
}

void	Animal::makeSound(void) const{
	std::cout << "ahsjhdjhajshds42miaoooBAU!" << std::endl;
}

Animal&	Animal::operator=(const Animal&ref) {
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}