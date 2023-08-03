#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap clapTrap("Genos");
	clapTrap.attack("ScarabeoASURA");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	ScavTrap scavTrap("OnePUnchMan");
	scavTrap.attack("ScarabeoASURA");
	scavTrap.beRepaired(20);
	scavTrap.guardGate();

	FragTrap FragTrap("Geppetto");
	FragTrap.attack("ScarabeoASURA");
	FragTrap.beRepaired(5);
	FragTrap.highFivesGuys();

    return 0;
}