#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat constructor called" << std::endl;
	if(grade > 150)
		throw GradeTooLowException();
	else if(grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(int decrement){
	if(_grade + decrement> 150)
		throw GradeTooLowException();
	else
		_grade += decrement;
}
void Bureaucrat::incrementGrade(int increment){
	if(_grade - increment < 1)
		throw GradeTooHighException();
	else
		_grade -= increment;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat has been DESTROYED" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& f){
	std::cout << f.getName() << ", bureaucrat grade " << f.getGrade() << '.';
	return os;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHigh";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLow";
}

void Bureaucrat::signForm(AForm& f){
	if(f.beSigned(*this))
		std::cout << _name << " signed " << f.getName() << '.' << std::endl;
	else
		std::cout << _name << " couldn't sign " << f.getName() << "because grade is too low." << std::endl;
}

void Bureaucrat::executeForm(AForm const & form){
	if(form.execute(*this))
		std::cout << _name << " executed " << form.getName() << '.' << std::endl;
	else
		std::cout << _name << " couldn't execute " << form.getName() << " because";
	if(!form.getSign() && form.getExecGrade() < this->getGrade())
		std::cout << " form isn't signed and grade is too low." << std::endl;
	else if(!form.getSign())
		std::cout << " form isn't signed" << std::endl;
	else if(form.getExecGrade() < this->getGrade())
		std::cout << " grade is too low." << std::endl;
}
