#include "Bureaucrat.hpp"

int	Bureaucrat::getGrade() {
	return this->grade;
}

std::string	Bureaucrat::getName() {
	return this->name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	this->grade = obj.grade;
	return *this;
}

Bureaucrat::Bureaucrat () : name("") {
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	*this = obj;
}

Bureaucrat::Bureaucrat(const std::string name, int n_grade) : name(name){
		try{
		if (n_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (n_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade = n_grade;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			this->grade = n_grade;
			return ;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			this->grade = n_grade;
			return ;
		}
}

void	Bureaucrat::incrementGrade() {
	try {
		if (this->grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade--;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade() {
	try {
		if (this->grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade++;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<< (std::ostream& os, Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}

Bureaucrat::~Bureaucrat() {
		std::cout << "Sir, don't to it pleaaasss.. xx" << name << std::endl;
	}
