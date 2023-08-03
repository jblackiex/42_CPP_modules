#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name) {
	std::cout << "ClapTrap Constructor Name called" << std::endl;
	this->Name = Name;
	this->AttakDamage = 0;
    this->EnergyPoints = 10;
    this->HitPoints = 4;
}

ClapTrap::ClapTrap() {
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default Destructor called ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = toCopy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap&ref) {
	if (this != &ref)
	{
		this->Name = ref.Name;
		this->AttakDamage = ref.AttakDamage;
		this->EnergyPoints = ref.EnergyPoints;
		this->HitPoints = ref.HitPoints;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->EnergyPoints || !this->HitPoints)
	{
		std::cout << "ClapTrap " << this->Name << " can't attack cause it's out of EnergyPoints or Hitpoints, who knows ?" << std::endl;
		return ;
	}
	--this->EnergyPoints;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttakDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->HitPoints || amount > this->HitPoints)
	{
		std::cout << "ClapTrap " << this->Name << " is Dead.. " << std::endl;
		this->HitPoints = 0;
		return ;
	}
	this->HitPoints =- amount;
	std::cout << "ClapTrap " << this->Name << "has lost " << amount << "HitPointss!" << this->AttakDamage << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->EnergyPoints || !this->HitPoints)
	{
		if (!this->EnergyPoints)
			std::cout << "ClapTrap " << this->Name << " is Dead.. can't recharge.. " << std::endl;
		else
			std::cout << "ClapTrap " << this->Name << "is out of EnergyPoints.. " << std::endl;
		return ;
	}
	--this->EnergyPoints;
	this->HitPoints += amount;
	std::cout << "ClapTrap " << this->Name << " got " << amount << " HitPoints back!" << std::endl;
}