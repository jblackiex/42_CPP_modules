#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string	name;
	int 				grade;

public:

    Bureaucrat(std::string name, int n_grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj);

	int	getGrade(void);
	std::string	getName(void);
	void	incrementGrade(void);
	void	decrementGrade(void);

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
std::ostream& operator<< (std::ostream& os, Bureaucrat& obj);


#endif