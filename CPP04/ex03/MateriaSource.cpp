#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
        this->materia[i] = NULL;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
		if (this->materia[i])
			delete this->materia[i];
}

void MateriaSource::learnMateria(AMateria* mat) {
	for (int i = 0; i < 4; i++)
		if (!this->materia[i])
			this->materia[i] = mat->clone();
	delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	if (!type.compare("ice"))
		return new Ice();
	else if (!type.compare("cure"))
		return new Cure();
	else
		return 0;
}

