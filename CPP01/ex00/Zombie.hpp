#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "Zombie.h"

class Zombie {
private:
	std::string	name;

public:

    Zombie(std::string name);
	Zombie() {};
	~Zombie();

	void	announce(void);
};

#endif