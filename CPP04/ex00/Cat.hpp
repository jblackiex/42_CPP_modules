#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
    Cat(std::string name);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &target);
    ~Cat();
   void makeSound() const;

};

#endif