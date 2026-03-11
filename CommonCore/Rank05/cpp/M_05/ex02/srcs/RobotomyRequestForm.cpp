#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45){
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)  : AForm(target, 72, 45){
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm has been DESTROYED" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

int RobotomyRequestForm::executeAction(const Bureaucrat &f) const{
		std::cout << "BZZ BZZZ... *DRILLING NOISES*" << std::endl;
		int nbr = rand() % 2;
		if(!nbr)
			return std::cout << f.getName() << " couldn't be robotomized..." << std::endl, 0;
		std::cout << f.getName() << " was robotomized succesfully!" << std::endl;
		return 1;
	}

