#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weaponn) {
	this->name = name;
	this->weapon = &weaponn;
}

void	HumanA::attack() {
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    }