#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string Name;

public:
	DiamondTrap();
    DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap&	operator= (const DiamondTrap &newobj);
	~DiamondTrap();

	using ScavTrap::attack;
	void whoAmI();
};

#endif