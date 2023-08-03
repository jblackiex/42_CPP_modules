#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
    WrongCat(std::string name);
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &target);
    ~WrongCat();
   void makeSound() const;

};

#endif