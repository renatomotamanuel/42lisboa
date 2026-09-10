#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat Empresario("ola", 150);
		std::cout << Empresario << std::endl;
		Empresario.decrementGrade(1);
		std::cout << Empresario << std::endl;
		Empresario.incrementGrade(1);
		std::cout << Empresario << std::endl;

		Bureaucrat Empresario2("ola3", 1);
		std::cout << Empresario2 << std::endl;
		Empresario2.incrementGrade(1);
		std::cout << Empresario2 << std::endl;
		Empresario2.decrementGrade(1);
		std::cout << Empresario2 << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	
}