#ifndef PRES_PARD_HPP
#define PRES_PARD_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class PresidentialPardonForm : public AForm {
private:
	std::string	target;

public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

	bool check_except(PresidentialPardonForm& obj);
	void execute(Bureaucrat const & executor) const;
	std::string	getTarget(void) const;

};

#endif