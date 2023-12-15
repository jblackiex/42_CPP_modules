#include "PresidentialPardonForm.hpp"

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm () : AForm("", 25, 5), target("") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try{
		Bureaucrat *tmp = const_cast<Bureaucrat*>(&executor);
		AForm *tmp2 = const_cast<PresidentialPardonForm*>(this);
		tmp->signForm(*tmp2);
		if (tmp2->getIsSigned() == false || tmp2->check_except(3) == false)
		{
			throw AForm::IsNotSignedException();
		}
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (AForm::IsNotSignedException& e)
	{
		std::cout << this->target << e.what() << std::endl;
		return ;
	}
}

std::string PresidentialPardonForm::getTarget(void) const{
	return this->target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
		std::cout << "PresidentialPardonForm destroyed.. xx " << target << std::endl;
	}