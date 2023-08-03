#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <string>
#include <iostream>

class A_Animal {
protected:
    std::string		type;

public:
	A_Animal();
	A_Animal(std::string Name);
	A_Animal(const A_Animal &toCopy);
	A_Animal&	operator= (const A_Animal&ref);
	virtual void	makeSound(void) const = 0;
	virtual ~A_Animal() {};
	const std::string&	getType(void) const;
};

#endif