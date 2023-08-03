#include "Character.hpp"

Character::Character(){
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->garbage[i] = NULL;
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->garbage[i])
		{
			delete this->garbage[i];
			this->garbage[i] = NULL;
		}
	}
}

Character::Character(const std::string& setName) : _name(setName){
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->garbage[i] = NULL;
}

Character::Character(const Character& src){
	*this = src;
}

Character& Character::operator=(const Character& src){
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
			this->materias[i] = src.materias[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	static int count = 0;

	if (this->materias[idx])
	{
		this->garbage[count++] = this->materias[idx];
		this->materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (this->materias[idx])
		this->materias[idx]->use(target);
}