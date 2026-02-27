#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(1){
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat constructor called" << std::endl;
	try{
		if(grade > 150)
			throw std::runtime_error("Bureaucrat::GradeTooHighException");
		else if(grade < 1)
			throw std::runtime_error("Bureaucrat::GradeTooLowException");
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat has been DESTROYED" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		//_name copy missing(?)
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat &Bureaucrat::operator<<(const Bureaucrat &other) {
	std::cout << _name << _grade;
	return *this;
}

std::string Bureaucrat::getName(){
	return _name;
}

int Bureaucrat::getGrade(){
	return _grade;
}