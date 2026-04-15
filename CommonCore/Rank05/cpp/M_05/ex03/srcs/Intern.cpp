#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::~Intern() { 
	std::cout << "Intern has been DESTROYED" << std::endl;
}

Intern::Intern(const Intern &other){
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string formType, std::string formName){
    std::string comments[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 4; ++i){
		if (formType == comments[i]){
			switch (i){
                case 0:{
                    std::cout << "Intern creates Robotomy Request." << std::endl;
                    AForm *temp = new RobotomyRequestForm(formName);
                    return temp;
                }
                case 1:{
                    std::cout << "Intern creates Presidential Pardon." << std::endl;
                    AForm *temp2 = new PresidentialPardonForm(formName);
                    return temp2;
                }
                case 2:{
                    std::cout << "Intern creates Shrubbery Creation." << std::endl;
                    AForm *temp3 = new ShrubberyCreationForm(formName);
                    return temp3;
                }
                default:{
                    std::cout << "Invalid Form name" << std::endl;
                    return NULL;
                }
            }
		}
	}
    return NULL;
}