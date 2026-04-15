#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5){
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
    _target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)  : AForm(target, 25, 5){
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
    _target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() { 
	std::cout << "PresidentialPardonForm has been DESTROYED" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other._target, 145, 137){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

int PresidentialPardonForm::executeAction(const Bureaucrat &f) const{
		std::cout << f.getName() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
		return 1;
	}

