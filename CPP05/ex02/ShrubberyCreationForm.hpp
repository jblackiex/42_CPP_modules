#ifndef SHRUB_CREAT_HPP
#define SHRUB_CREAT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class ShrubberyCreationForm : public AForm {
private:
	std::string	target;

public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);

	std::string	getTarget(void) const;
	void execute(Bureaucrat const & executor) const;
};

#endif