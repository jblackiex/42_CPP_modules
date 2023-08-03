#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	std::string	type;
	Brain *brn;
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &target);
	~Cat();
	void makeSound() const;
};

#endif