#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(0), _reqSign(1), _reqExec(1){
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int reqSign, int reqExec) : _name(name), _signed(0), _reqSign(reqSign), _reqExec(reqExec){
	std::cout << "AForm constructor called" << std::endl;
	if(reqSign > 150)
		throw GradeTooLowException();
	else if(reqSign < 1)
		throw GradeTooHighException();
	if(reqExec > 150)
		throw GradeTooLowException();
	else if(reqExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {
	std::cout << "AForm has been DESTROYED" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _reqSign(other._reqSign), _reqExec(other._reqExec){
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

AForm &AForm::operator=(const AForm &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() const{
	return _name;
}

int AForm::getSignGrade() const{
	return _reqSign;
}

int AForm::getSign() const{
	return _signed;
}

int AForm::getExecGrade() const{
	return _reqExec;
}

std::ostream& operator<<(std::ostream& os, AForm& f){
	std::cout << f.getName() << ", Aform sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade();
	if(f.getSign())
		std::cout << " and is signed." << std::endl;
	else
		std::cout << " and is unsigned." << std::endl;
	return os;
}

int AForm::beSigned(Bureaucrat& f){
	if(_reqSign < f.getGrade())
		throw GradeTooLowException();
	else{
		_signed = 1;
		return 1;
	}
}

int AForm::execute(Bureaucrat const & executor) const{
	if(!_signed)
		throw FormNotSignedException();
	else if(_reqExec < executor.getGrade())
		throw GradeTooLowException();
	else{
		executeAction(executor);
		return 1;
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHigh";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLow";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "AForm::NotSigned";
}

