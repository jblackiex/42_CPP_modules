#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
private:
	const std::string	name;
	bool                isSigned;
	const int 			gradesign;
	const int 			gradeexec;

public:

	AForm(std::string name, int gradesign, int gradeexec);
	AForm(const AForm& obj);
	AForm();
	virtual ~AForm();
	AForm& operator=(const AForm& obj);

	int	getGradeSign(void);
	int getGradeExec(void);
	bool getIsSigned(void) const;
	std::string	getName(void) const;

	void	beSigned(Bureaucrat& obj) ;

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

	class IsNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return (" Form is not signed! Bad Request.");
			}
	};

	bool check_except(int flag);
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<< (std::ostream& os, const AForm& obj);

#endif