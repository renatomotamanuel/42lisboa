#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
private:
	std::string const _name;
	bool _signed;
	int const _reqSign;
	int const _reqExec;
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(std::string name, int reqSign, int reqExec);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	int beSigned(Bureaucrat& f);
	std::string getName();
	int getSignGrade();
	int getSign();
	int getExecGrade();
};

#endif