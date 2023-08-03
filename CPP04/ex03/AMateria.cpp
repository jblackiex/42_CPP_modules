#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

std::string const & AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}