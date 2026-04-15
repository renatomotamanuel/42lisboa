#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{
private:
    std::string _target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm(std::string target);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	int executeAction(const Bureaucrat &f) const;
};

#endif