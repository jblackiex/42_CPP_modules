#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* materias[4];
	AMateria* garbage[100];
	Character();

public:
	Character(const std::string& setName);
	Character(const Character& src);
	Character& operator=(const Character& src);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
	~Character();
};

#endif