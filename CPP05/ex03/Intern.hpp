#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <cstring>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;
class Intern {
public:
	Intern(const Intern& obj);
	Intern();
	~Intern();
	Intern& operator=(const Intern& obj);

	AForm* makeForm(std::string name_form, std::string target);

};

#endif