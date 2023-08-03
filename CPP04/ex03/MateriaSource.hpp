#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
private:
	std::string _type;
	AMateria* materia[4];
public:
	MateriaSource();
	~MateriaSource();

	void learnMateria(AMateria* mat);
	AMateria* createMateria(std::string const & type);
};




#endif