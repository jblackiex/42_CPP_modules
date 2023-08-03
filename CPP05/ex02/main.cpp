#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>
int main()
{
  {
    Bureaucrat prova("prova", 10);
    PresidentialPardonForm form("Captain");
    std::cout << form.getName() << std::endl;
    std::cout << form.getGradeSign() << std::endl;
    form.execute(prova);
    // prova.executeForm(form);
  }
    std::system("clear");
  {
    std::cout << std::endl;
    Bureaucrat prova("prova", 120);
    ShrubberyCreationForm form2("ciao");
    form2.execute(prova);
    std::string line;
    std::ifstream file("ciao_shrubbery");
    while (std::getline(file, line))
    {
      std::cout << line << std::endl;
      usleep(150000);
    }
    file.close();
  }
  return 0;
}