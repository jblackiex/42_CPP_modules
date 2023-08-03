#ifndef DOG_HPP
#define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal {
private:
    Brain *brn;
public:
	Dog();
    Dog(std::string name);
	Dog(const Dog &copy);
	Dog &operator= (const Dog &target);
    ~Dog();
	void makeSound() const;
};

#endif