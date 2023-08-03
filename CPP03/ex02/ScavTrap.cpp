#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default Constructor called, but is ScavTrap.." << std::endl;
	this->Name = "";
    this->AttakDamage = 20;
    this->EnergyPoints = 50;
    this->HitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Constructor Name called" << std::endl;
	this->Name = name;
    this->AttakDamage = 20;
    this->EnergyPoints = 50;
    this->HitPoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &target)
{
	if (this != &target){
		this->Name = target.Name;
		this->AttakDamage = target.AttakDamage;
		this->HitPoints = target.HitPoints;
		this->EnergyPoints = target.EnergyPoints;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << this->Name << " attacks " << target << " with its special attack, causing " << this->AttakDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->Name << " is now in Gatekeeper mode!" << std::endl;
}