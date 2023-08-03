#include "AForm.hpp"

int	AForm::getGradeSign() {
	return this->gradesign;
}

int	AForm::getGradeExec() {
	return this->gradeexec;
}

std::string	AForm::getName() const{
	return this->name;
}

bool	AForm::getIsSigned() const{
	return this->isSigned;
}

AForm& AForm::operator=(const AForm& obj) {
	this->isSigned = obj.isSigned;
	return *this;
}

AForm::AForm () : name(""), isSigned(false), gradesign(150), gradeexec(150) {
}

AForm::AForm(const AForm& obj) : name(obj.name), isSigned(obj.isSigned), gradesign(obj.gradesign), gradeexec(obj.gradeexec){
}

AForm::AForm(const std::string name, int gradesign, int gradeexec) : name(name), isSigned(false), gradesign(gradesign), gradeexec(gradeexec){
		try{
		if (gradesign < 1 || gradeexec < 1)
			throw AForm::GradeTooHighException();
		else if (gradesign > 150 || gradeexec > 150)
			throw AForm::GradeTooLowException();
		}
		catch (AForm::GradeTooHighException& e)
		{
			return ;
		}
		catch (AForm::GradeTooLowException& e)
		{
			return ;
		}
}

std::ostream& operator<< (std::ostream& os, AForm& obj) {
	os << obj.getName() << ", AForm is signed " << obj.getIsSigned() << " , AForm gradesign " << obj.getGradeSign() << " , AForm gradeexec " << obj.getGradeExec() << std::endl;
	return os;
}

void	AForm::beSigned(Bureaucrat& obj) {
	if (gradesign > 150 || gradeexec > 150 || gradesign < 1 || gradeexec < 1)
		return ;
	try {
		if (obj.getGrade() > this->gradesign)
			throw AForm::GradeTooLowException();
		this->isSigned = true;
	}
	catch (AForm::GradeTooLowException& e)
	{
		return ;
	}
}

bool AForm::check_except(int flag) {
	switch (flag)
	{
		case 1:
			if (this->gradesign > 145 || this->gradeexec > 137)
			{
				this->isSigned = false;
				return false;
			}
			break;
		case 2:
			if (this->gradesign > 72 || this->gradeexec > 45)
			{
				this->isSigned = false;
				return false;
			}
			break;
		case 3:
			if (this->gradesign > 25 || this->gradeexec > 5)
			{
				this->isSigned = false;
				return false;
			}
			break;
	}
	return true;
}

AForm::~AForm() {
		std::cout << "AForm destroyed.. xx " << this->name << std::endl;
	}
