#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat constructor called" << std::endl;
	try{
		if(grade > 150)
			throw std::runtime_error("Bureaucrat::GradeTooLowException");
		else if(grade < 1)
			throw std::runtime_error("Bureaucrat::GradeTooHighException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade(void){
	try{
		_grade++;
		if(_grade > 150)
			throw std::runtime_error("Bureaucrat::GradeTooLowException");
	}
	catch (std::exception & e){
		_grade--;
		std::cout << e.what() << std::endl;
	}
}
void Bureaucrat::incrementGrade(void){
	try{
		_grade--;
		if(_grade < 1)
			throw std::runtime_error("Bureaucrat::GradeTooHighException");
	}
	catch (std::exception & e){
		_grade++;
		std::cout << e.what() << std::endl;
	}
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
	std::cout << f.getName() << ", bureaucrat grade " << f.getGrade() << '.' << std::endl;
	return os;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}