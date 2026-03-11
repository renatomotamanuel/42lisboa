#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(0), _reqSign(1), _reqExec(1){
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int reqSign, int reqExec) : _name(name), _signed(0), _reqSign(reqSign), _reqExec(reqExec){
	std::cout << "AForm constructor called" << std::endl;
	try{
		if(reqSign > 150)
			throw std::runtime_error("AForm::GradeTooLowException");
		else if(reqSign < 1)
			throw std::runtime_error("AForm::GradeTooHighException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
		if(reqExec > 150)
			throw std::runtime_error("AForm::GradeTooLowException");
		else if(reqExec < 1)
			throw std::runtime_error("AForm::GradeTooHighException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

AForm::~AForm() {
	std::cout << "AForm has been DESTROYED" << std::endl;
}

AForm::AForm(const AForm &other) : _reqSign(other._reqSign), _reqExec(other._reqExec){
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

int AForm::getSignGrade(){
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
	try{
		if(_reqSign > f.getGrade())
			throw std::runtime_error("AForm::GradeTooLowException");
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

int AForm::execute(Bureaucrat const & executor) const{
	try{
		if(!_signed)
			throw std::runtime_error("AForm::FormNotSignedException");
		else if(_reqExec > executor.getGrade())
			throw std::runtime_error("AForm::GradeTooLowException");
		else{
			executeAction(executor);
			return 1;
		}
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
		return (0);
	}
}
