#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	std::string	type;
	Brain *brn;
public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator= (const Dog &target);
    ~Dog();
	void makeSound() const;
};

#endif