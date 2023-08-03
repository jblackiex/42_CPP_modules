#include "Form.hpp"

int	Form::getGradeSign() {
	return this->gradesign;
}

int	Form::getGradeExec() {
	return this->gradeexec;
}

std::string	Form::getName() {
	return this->name;
}

bool	Form::getIsSigned() {
	return this->isSigned;
}

Form& Form::operator=(const Form& obj) {
	this->isSigned = obj.isSigned;
	return *this;
}

Form::Form () : name(""), isSigned(false), gradesign(150), gradeexec(150) {
}

Form::Form(const Form& obj) : name(obj.name), isSigned(obj.isSigned), gradesign(obj.gradesign), gradeexec(obj.gradeexec){
}

Form::Form(const std::string name, int gradesign, int gradeexec) : name(name), isSigned(false), gradesign(gradesign), gradeexec(gradeexec){
		try{
		if (gradesign < 1 || gradeexec < 1)
			throw Form::GradeTooHighException();
		else if (gradesign > 150 || gradeexec > 150)
			throw Form::GradeTooLowException();
		}
		catch (Form::GradeTooHighException& e)
		{
			return ;
		}
		catch (Form::GradeTooLowException& e)
		{
			return ;
		}
}

std::ostream& operator<< (std::ostream& os, Form& obj) {
	os << obj.getName() << ", Form is signed " << obj.getIsSigned() << " , Form gradesign " << obj.getGradeSign() << " , Form gradeexec " << obj.getGradeExec() << std::endl;
	return os;
}

void	Form::beSigned(Bureaucrat& obj) {
	if (gradesign > 150 || gradeexec > 150 || gradesign < 1 || gradeexec < 1)
		return ;
	try {
		if (obj.getGrade() > this->gradesign)
			throw Form::GradeTooLowException();
		this->isSigned = true;
	}
	catch (Form::GradeTooLowException& e)
	{
		return ;
	}
}

Form::~Form() {
		std::cout << "Form destroyed.. xx" << name << std::endl;
	}
