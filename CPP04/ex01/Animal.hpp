#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string		type;

public:
	Animal();
	Animal(std::string Name);
	Animal(const Animal &toCopy);
	Animal&	operator= (const Animal&ref);
	virtual void	makeSound(void) const;
	virtual ~Animal() {};
	const std::string&	getType(void) const;
};

#endif