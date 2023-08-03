#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string Name) {
	std::cout << "WrongAnimal Constructor Name called" << std::endl;
	this->type = Name;
}
WrongAnimal::WrongAnimal() {
	std::cout << "Default Constructor WrongAnimal called" << std::endl;
	this->type = "Animalesbalgiato";
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = toCopy;
}

const std::string&	WrongAnimal::getType(void) const{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "ahsjhdjhajshds42miaoooBAU!" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal&ref) {
	if (this != &ref)
		this->type = ref.type;
	return (*this);
}