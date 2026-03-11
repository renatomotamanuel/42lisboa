#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	
	Bureaucrat Empresario("ola", 150);
	ShrubberyCreationForm teste("test");
	ShrubberyCreationForm teste2;
	teste2 = teste;
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	std::cout << "HEREEEE" << std::endl;
	Empresario.executeForm(teste);
	Empresario.signForm(teste);
	Empresario.executeForm(teste);
	Bureaucrat Empresario2("ola2", 1);
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
}