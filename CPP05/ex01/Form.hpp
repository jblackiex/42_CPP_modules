#ifndef FORM
#define FORM

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
private:
	const std::string	name;
	bool                isSigned;
	const int 			gradesign;
	const int 			gradeexec;

public:

	Form(std::string name, int gradesign, int gradeexec);
	Form(const Form& obj);
	Form();
	~Form();
	Form& operator=(const Form& obj);

	int	getGradeSign(void);
	int getGradeExec(void);
	bool getIsSigned(void);
	std::string	getName(void);

	void	beSigned(Bureaucrat& obj);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too high Sir!");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Grade is too low Sir!");
			}
	};
};
std::ostream& operator<< (std::ostream& os, Form& obj);

#endif