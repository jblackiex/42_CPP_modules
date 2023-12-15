#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define TREE_CMD "find | sed 's|[^/]*/|- |g' > "
#define GREEN "\033[0;32m"
#define END "\033[0m"
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
    ShrubberyCreationForm form2("NOTasciitree");
    form2.execute(prova);
    std::string line;
    std::ifstream file("NOTasciitree_shrubbery");
    while (std::getline(file, line))
    {
      std::cout << line << std::endl;
      usleep(150000);
    }
    std::cout << std::endl;
    file.close();
  }

  {
    ShrubberyCreationForm prov("asciitree");
    std::string cmd = TREE_CMD;
    const std::string fileName = prov.getTarget() + "_shrubbery";
    cmd += fileName;

    std::system(cmd.c_str());
    std::cout << GREEN;
    std::cout << std::endl << "But then.. you have the real ASCII Tree.. from this path" << std::endl;
    std::ifstream file(fileName.c_str());
    std::string line;
    while (std::getline(file, line))
    {
      std::cout << line << std::endl;
      usleep(150000);
    }
    file.close();
    std::cout << END;
    std::cout << std::endl;
  }
  return 0;
}