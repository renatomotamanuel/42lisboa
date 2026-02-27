#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Form bueimportante("topsecret", 120, 120);
	Bureaucrat Empresario("ola", 150);
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	
	Bureaucrat Empresario2("ola2", 1);
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario.signForm(bueimportante);
	Empresario2.signForm(bueimportante);
}