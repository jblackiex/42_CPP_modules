#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default Constructor called, but is Brain.. so be careful" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called (it's very fast) " << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &target)
{
	if (this != &target)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = target.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain Destructor called (!)" << std::endl;
}