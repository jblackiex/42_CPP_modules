#include "ClapTrap.hpp"

int	main() {
	ClapTrap prova("mouse");
	ClapTrap copyprova(prova);
	prova.attack("trappola");
	prova.beRepaired(1);
	prova.takeDamage(12);
}