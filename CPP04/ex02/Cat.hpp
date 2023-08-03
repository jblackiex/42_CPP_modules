#ifndef CAT_HPP
#define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal {
private:
	Brain *brn;
public:
	Cat();
	Cat(std::string name);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &target);
	~Cat();
	void makeSound() const;
};

#endif