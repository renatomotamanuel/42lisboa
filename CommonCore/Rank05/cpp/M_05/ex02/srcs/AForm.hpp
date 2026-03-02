#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
private:
	std::string const _name;
	bool _signed;
	int const _reqSign;
	int const _reqExec;
public:
	AForm();
	virtual ~AForm();
	AForm(const AForm &other);
	AForm(std::string name, int reqSign, int reqExec);
    AForm &operator=(const AForm &other);
	int beSigned(Bureaucrat& f);
	std::string getName();
	int getSignGrade();
	int getSign();
	int getExecGrade();
};

#endif