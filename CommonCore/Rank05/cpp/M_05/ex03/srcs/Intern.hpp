#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    AForm *makeForm(std::string formType, std::string formName);
};

#endif