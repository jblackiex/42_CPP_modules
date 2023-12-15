#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int main()
{
  {
    Intern someRandomIntern;
    AForm *rrf;
  
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (rrf)
    {
      std::cout << "Aform is --> " << rrf->getName() << std::endl;
      std::cout << "RobotomyRequestForm grade_sign is --> " << rrf->getGradeSign() << std::endl;
    }
    if (rrf)
      delete rrf;
    return 0;
  }
}