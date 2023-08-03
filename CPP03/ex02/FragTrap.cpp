#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Default Constructor called, but is FragTrap.." << std::endl;
	this->Name = "";
    this->AttakDamage = 30;
    this->EnergyPoints = 100;
    this->HitPoints = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor Name called" << std::endl;
	this->Name = name;
    this->AttakDamage = 30;
    this->EnergyPoints = 100;
    this->HitPoints = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &target)
{
	if (this != &target){
		this->Name = target.Name;
		this->AttakDamage = target.AttakDamage;
		this->HitPoints = target.HitPoints;
		this->EnergyPoints = target.EnergyPoints;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->Name << " attacks " << target << " with its special attack, causing " << this->AttakDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "High Five Guys! Good Job!" << std::endl;
}