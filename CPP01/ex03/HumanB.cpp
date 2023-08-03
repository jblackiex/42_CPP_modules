#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	this->name = name;
	this->weapon = NULL;
}

void	HumanB::attack() {
		if (weapon)
			std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
        else
			std::cout << this->name << " is unarmed and cannot attack" << std::endl;
    }
void	HumanB::setWeapon(Weapon& weapon) {
		this->weapon = &weapon;
	}