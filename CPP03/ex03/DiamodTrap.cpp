#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttakDamage = FragTrap::AttakDamage;
	this->Name = "";
	ClapTrap::Name = "";
	std::cout << "Default DiamondTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap Constructor Name called" << std::endl;
	this->Name = name;
	ClapTrap::Name = name + "_clap_name";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttakDamage = FragTrap::AttakDamage;
}

DiamondTrap&	DiamondTrap::operator= ( const DiamondTrap &newobj) {
	if (this != &newobj)
	{
		this->Name = newobj.Name;
		this->AttakDamage = newobj.AttakDamage;
		this->HitPoints = newobj.HitPoints;
		this->EnergyPoints = newobj.EnergyPoints;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamodTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Diamond " << this->Name << " made out of " << ClapTrap::Name << std::endl;
}