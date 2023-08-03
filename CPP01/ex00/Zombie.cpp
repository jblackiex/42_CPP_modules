#include "Zombie.h"

void	Zombie::announce() {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) {
		this->name = name;
	}

Zombie::~Zombie() {
		std::cout << "AAARrrrragggggzshhh!! " << name << std::endl;
	}
