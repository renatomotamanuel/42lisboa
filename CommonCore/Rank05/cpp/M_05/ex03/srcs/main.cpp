#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(0));
	Intern someRandomIntern;
    AForm* rrf;
	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
	Bureaucrat Empresario("ola", 150);
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(*rrf);
	Empresario.signForm(*rrf);
	Empresario.executeForm(*rrf);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	Bureaucrat Empresario2("ola2", 1);
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(*rrf);
	Empresario2.signForm(*rrf);
	Empresario2.executeForm(*rrf);
	
	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Obama");
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(*rrf);
	Empresario.signForm(*rrf);
	Empresario.executeForm(*rrf);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(*rrf);
	Empresario2.signForm(*rrf);
	Empresario2.executeForm(*rrf);

	std::cout << std::endl << std::endl <<  "Lower grade testing" << std::endl << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Tree");
	std::cout << Empresario << std::endl;
	Empresario.decrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.incrementGrade();
	std::cout << Empresario << std::endl;
	Empresario.executeForm(*rrf);
	Empresario.signForm(*rrf);
	Empresario.executeForm(*rrf);
	std::cout << std::endl << std::endl <<  "Higher grade testing" << std::endl << std::endl;
	std::cout << Empresario2 << std::endl;
	Empresario2.incrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.decrementGrade();
	std::cout << Empresario2 << std::endl;
	Empresario2.executeForm(*rrf);
	Empresario2.signForm(*rrf);
	Empresario2.executeForm(*rrf);
}