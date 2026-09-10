#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(0));
	AForm* rrf;
	try{
		Intern someRandomIntern;
		std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
		Bureaucrat Empresario("ola", 150);
		Bureaucrat Empresario2("ola2", 1);
    	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << Empresario << std::endl;
		Empresario.decrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.incrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.executeForm(*rrf);
		Empresario.signForm(*rrf);
		Empresario.executeForm(*rrf);
		std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
		std::cout << Empresario2 << std::endl;
		Empresario2.incrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.decrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.executeForm(*rrf);
		Empresario2.signForm(*rrf);
		Empresario2.executeForm(*rrf);
	}
	catch (std::exception & e){
		if(rrf)
			delete rrf;
		std::cout << e.what() << std::endl;
		return 0;
	}
	if(rrf)
		delete rrf;
	try{
		Intern someRandomIntern;
		Bureaucrat Empresario("ola", 150);
		Bureaucrat Empresario2("ola2", 1);
		std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
    	rrf = someRandomIntern.makeForm("presidential pardon", "Obama");
		std::cout << Empresario << std::endl;
		Empresario.decrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.incrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.executeForm(*rrf);
		Empresario.signForm(*rrf);
		Empresario.executeForm(*rrf);
		std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
		std::cout << Empresario2 << std::endl;
		Empresario2.incrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.decrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.executeForm(*rrf);
		Empresario2.signForm(*rrf);
		Empresario2.executeForm(*rrf);
	}
	catch (std::exception & e){
		if(rrf)
			delete rrf;
		std::cout << e.what() << std::endl;
		return 0;
	}
	if(rrf)
		delete rrf;
	try{
		Intern someRandomIntern;
		Bureaucrat Empresario("ola", 150);
		Bureaucrat Empresario2("ola2", 1);
		std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
    	rrf = someRandomIntern.makeForm("shrubbery creation", "Tree");
		std::cout << Empresario << std::endl;
		Empresario.decrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.incrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.executeForm(*rrf);
		Empresario.signForm(*rrf);
		Empresario.executeForm(*rrf);
		std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
		std::cout << Empresario2 << std::endl;
		Empresario2.incrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.decrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.executeForm(*rrf);
		Empresario2.signForm(*rrf);
		Empresario2.executeForm(*rrf);
	}
	catch (std::exception & e){
		if(rrf)
			delete rrf;
		std::cout << e.what() << std::endl;
		return 0;
	}
	if(rrf)
		delete rrf;
}