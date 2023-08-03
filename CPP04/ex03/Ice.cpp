#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

AMateria* Ice::clone() const{
	return (new Ice());
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
