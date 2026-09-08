#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
	Bureaucrat Empresario("ola", 150);
	ShrubberyCreationForm shruberry("test");
	ShrubberyCreationForm shruberry2;
	shruberry2 = shruberry;
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(shruberry);
	Empresario.signForm(shruberry);
	Empresario.executeForm(shruberry);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	Bureaucrat Empresario2("ola2", 1);
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(shruberry);
	Empresario2.signForm(shruberry);
	Empresario2.executeForm(shruberry);
	
	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
	RobotomyRequestForm robotomy("test");
	RobotomyRequestForm robotomy2;
	robotomy2 = robotomy;
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(robotomy);
	Empresario.signForm(robotomy);
	Empresario.executeForm(robotomy);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(robotomy);
	Empresario2.signForm(robotomy);
	Empresario2.executeForm(robotomy);

	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
	PresidentialPardonForm presidential("test");
	PresidentialPardonForm presidential2;
	presidential2 = presidential;
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(presidential);
	Empresario.signForm(presidential);
	Empresario.executeForm(presidential);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(presidential);
	Empresario2.signForm(presidential);
	Empresario2.executeForm(presidential);
}