#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "Default Constructor called, but is WrongCat.. so be caerrful" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
	std::cout << "WrongCat Constructor Name called, be knid" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called (it's very slent) " << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &target)
{
	if (this != &target)
		this->type = target.type;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Nyaaa!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor cleed (miAAAHhdididvhhhhSSSssh!)" << std::endl;
}