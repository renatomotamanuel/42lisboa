#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(0), _reqSign(1), _reqExec(1){
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int reqSign, int reqExec) : _name(name), _signed(0), _reqSign(reqSign), _reqExec(reqExec){
	std::cout << "Form constructor called" << std::endl;
	if(reqSign > 150)
		throw GradeTooLowException();
	else if(reqSign < 1)
		throw GradeTooHighException();
	if(reqExec > 150)
		throw GradeTooLowException();
	else if(reqExec < 1)
		throw GradeTooHighException();
}

Form::~Form() {
	std::cout << "Form has been DESTROYED" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _reqSign(other._reqSign), _reqExec(other._reqExec){
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() const{
	return _name;
}

int Form::getSignGrade() const{
	return _reqSign;
}

int Form::getSign() const{
	return _signed;
}

int Form::getExecGrade() const{
	return _reqExec;
}

std::ostream& operator<<(std::ostream& os, Form& f){
	std::cout << f.getName() << ", form sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade();
	if(f.getSign())
		std::cout << " and is signed." << std::endl;
	else
		std::cout << " and is unsigned." << std::endl;
	return os;
}

int Form::beSigned(Bureaucrat& f){
	if(_reqSign < f.getGrade())
		throw GradeTooLowException();
	else{
		_signed = 1;
		return 1;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHigh";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLow";
}