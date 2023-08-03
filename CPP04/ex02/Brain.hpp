#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "A_Animal.hpp"

class Brain {
private:
	std::string	ideas[100];
public:
    Brain();
    Brain(const Brain &copy);
    Brain &operator=(const Brain &target);
    ~Brain();
};

#endif