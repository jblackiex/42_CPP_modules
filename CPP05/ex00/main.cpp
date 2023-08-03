#include "Bureaucrat.hpp"

int	main()
{
  Bureaucrat	prova;
  std::cout << prova.getName() << std::endl;
  prova.decrementGrade();
  prova.incrementGrade();
  std::cout << prova.getGrade() << std::endl;
  return 0;
}