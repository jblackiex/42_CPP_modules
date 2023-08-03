#include "Weapon.hpp"

std::string&	Weapon::getType(){
		return this->type;
	}

void			Weapon::setType(const std::string& type) {
		this->type = type;
    }