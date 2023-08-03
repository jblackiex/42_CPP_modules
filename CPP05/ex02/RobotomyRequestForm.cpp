#include "RobotomyRequestForm.hpp"

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm () : AForm("", 72, 45), target("") {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try{
		Bureaucrat *tmp = const_cast<Bureaucrat*>(&executor);
		AForm *tmp2 = const_cast<RobotomyRequestForm*>(this);
		tmp->signForm(*tmp2);
		if (tmp2->getIsSigned() == false || tmp2->check_except(2) == false)
		{
			throw AForm::IsNotSignedException();
		}
		srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
		else
			std::cerr << this->target << " robotomy not possible Xx.." << std::endl;
	}
		catch (AForm::IsNotSignedException& e)
		{
			std::cout << this->target << e.what() << std::endl;
			return ;
		}
}

std::string RobotomyRequestForm::getTarget(void) {
	return this->target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
		std::cout << "RobotomyRequestForm destroyed.. xx " << target << std::endl;
	}
