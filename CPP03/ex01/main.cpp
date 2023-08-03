#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap clapTrap("Genos");
	clapTrap.attack("ScarabeoASURA");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	ScavTrap scavTrap("OnePUnchMan");
	scavTrap.attack("ScarabeoASURA");
	scavTrap.beRepaired(20);
	scavTrap.guardGate();

    return 0;
}