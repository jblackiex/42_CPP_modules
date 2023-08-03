#include "Intern.hpp"

Intern& Intern::operator=(const Intern& obj) {
	if (this != &obj)
		*this = obj;
	return *this;
}

Intern::Intern () {
}

Intern::Intern(const Intern& obj) {
	*this = obj;
}

AForm *Intern::makeForm(std::string name_form, std::string target) {
	AForm *form;
	int i;
	std::string cont[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for(i = 0; i < 3; i++)
		if (strcmp(name_form.c_str(), cont[i].c_str()))
			break;
	switch(i){
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		case 3:	
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Intern can't create " << name_form << std::endl;
			return NULL;
	}
		std::cout << "Intern creates " << name_form << std::endl;
	return form;
}

Intern::~Intern() {
		std::cout << "Intern destroyed.. xx " << std::endl;
	}