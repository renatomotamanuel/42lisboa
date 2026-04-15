#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137){
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
    _target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : AForm(target, 145, 137){
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm has been DESTROYED" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other._target, 145, 137){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

int ShrubberyCreationForm::executeAction(const Bureaucrat &f) const{
		std::string temp = f.getName();
		temp += "_shrubbery";
		std::ofstream outfile (temp.c_str());
		if(!outfile.is_open())
			return std::cout << "Error opening Shrubbery file." << std::endl, 0;
		outfile << "       ###\n";
		outfile << "      #o###\n";
		outfile << "    #####o###\n";
		outfile << "   #o#\\#|#/###\n";
		outfile << "    ###\\|/#o#\n";
		outfile << "     # }|{  #\n";
		outfile << "       }|{\n";
		outfile.close();
		return 1;
	}

