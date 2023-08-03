#include "Bureaucrat.hpp"

int	main()
{
  Bureaucrat	prova("prova", 90);
  Form      form("prova2", 9, 10);
  std::cout << form.getName() << std::endl;
  std::cout << form.getGradeSign() << std::endl;
  prova.signForm(form);
  form.beSigned(prova);
  return 0;
}