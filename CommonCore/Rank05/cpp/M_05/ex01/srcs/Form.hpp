#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {
private:
	std::string const _name;
	bool _signed;
	int _reqSign;
	int _reqExec;
public:
	Form();
	~Form();
	Form(const Form &other);
	Form(std::string name, int reqSign, int reqExec);
    Form &operator=(const Form &other);
	int beSigned(Bureaucrat& f);
	std::string getName();
	int getSignGrade();
	int getSign();
	int getExecGrade();
};

#endif