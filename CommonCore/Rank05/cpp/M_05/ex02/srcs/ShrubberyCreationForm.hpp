#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
private:
    std::string _target;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	int executeAction(const Bureaucrat &f) const;
};

#endif