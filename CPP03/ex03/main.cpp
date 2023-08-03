#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {
	ClapTrap carbon("Carbon");
	carbon.attack("Science");
	DiamondTrap diamond_problem("Diamond");
	diamond_problem.whoAmI();
	diamond_problem.attack("Science");
	diamond_problem.beRepaired(20);
	diamond_problem.takeDamage(0);
    return 0;
}