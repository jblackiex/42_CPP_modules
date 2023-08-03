#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string		type;

public:
	WrongAnimal();
	WrongAnimal(std::string Name);
	WrongAnimal(const WrongAnimal &toCopy);
	WrongAnimal&	operator= (const WrongAnimal&ref);
	void	makeSound(void) const;
	~WrongAnimal() {};
	const std::string&	getType(void) const;
};

#endif