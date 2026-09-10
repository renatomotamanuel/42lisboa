#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Form bueimportante("topsecret", 120, 120);
		Bureaucrat Empresario("ola", 150);
		std::cout << Empresario << std::endl;
		Empresario.decrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.incrementGrade(1);
		std::cout << Empresario << std::endl;
		
		Bureaucrat Empresario2("ola2", 1);
		std::cout << Empresario2 << std::endl;
		Empresario2.incrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.decrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario.signForm(bueimportante);
		Empresario2.signForm(bueimportante);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}