#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("", 145, 137), target("") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), target(obj.target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	try{
		Bureaucrat *tmp = const_cast<Bureaucrat*>(&executor);
		AForm *tmp2 = const_cast<ShrubberyCreationForm*>(this);
		tmp->signForm(*tmp2);
		if (tmp2->getIsSigned() == false || tmp2->check_except(1) == false)
		{
			throw AForm::IsNotSignedException();
		}
		std::cout << std::endl;
		std::cout <<"I Know, this is not a tree.. but a perfect Tree instead.. " << std::endl;
		std::cout << std::endl; 
		std::string tree = this->target + "_shrubbery";
		std::ofstream ofs(tree.c_str());
		ofs << "                   A" << std::endl;
    ofs << "           _______/ \\_______" << std::endl;
    ofs << "          /                 \\" << std::endl;
    ofs << "         B                   C" << std::endl;
    ofs << "      __/ \\__             __/ \\__" << std::endl;
    ofs << "     /       \\           /       \\" << std::endl;
    ofs << "    D         E         F         G" << std::endl;
    ofs << "   / \\       / \\       / \\       / \\" << std::endl;
    ofs << "  H   I     J   K     L   M     N   O" << std::endl;
    ofs << " / \\ / \\   / \\ / \\   / \\ / \\   / \\ / \\" << std::endl;
    ofs << "P  Q R S  T U V W  X Y Z a b c d e f g" << std::endl;
	}
		catch (AForm::IsNotSignedException& e)
		{
			std::cout << this->target << e.what() << std::endl;
			return ;
		}
}

std::string ShrubberyCreationForm::getTarget(void) const{
	return this->target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
		std::cout << "ShrubberyCreationForm destroyed.. xx " << target << std::endl;
	}
