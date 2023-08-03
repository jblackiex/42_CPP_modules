#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string		Name;
	unsigned int	HitPoints;
	unsigned int	EnergyPoints;
	unsigned int	AttakDamage;

public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &toCopy);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
ClapTrap&	operator= (const ClapTrap&ref);

};

#endif