#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(0), _reqSign(1), _reqExec(1){
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, int reqSign, int reqExec) : _name(name), _signed(0), _reqSign(reqSign), _reqExec(reqExec){
	std::cout << "Form constructor called" << std::endl;
	try{
		if(reqSign > 150)
			throw std::runtime_error("Form::GradeTooLowException");
		else if(reqSign < 1)
			throw std::runtime_error("Form::GradeTooHighException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
		if(reqExec > 150)
			throw std::runtime_error("Form::GradeTooLowException");
		else if(reqExec < 1)
			throw std::runtime_error("Form::GradeTooHighException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

Form::~Form() {
	std::cout << "Form has been DESTROYED" << std::endl;
}

Form::Form(const Form &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		//_name copy missing(?)
		this->_reqSign = other._reqSign;
		this->_reqExec = other._reqExec;
	}
	return *this;
}

std::string Form::getName(){
	return _name;
}

int Form::getSignGrade(){
	return _reqSign;
}

int Form::getSign(){
	return _signed;
}

int Form::getExecGrade(){
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
	try{
		if(_reqSign > f.getGrade())
			throw std::runtime_error("Form::GradeTooLowException");
		else{
			_signed = 1;
			return 1;
		}
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
		return (0);
	}
}