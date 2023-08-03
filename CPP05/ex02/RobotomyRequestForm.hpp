#ifndef ROB_REQ_HPP
#define ROB_REQ_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#include "Bureaucrat.hpp"
class Bureaucrat;
class RobotomyRequestForm : public AForm {
private:
	std::string	target;

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

	void execute(Bureaucrat const & executor) const;
	std::string	getTarget(void);

};

#endif