#include <iostream>
#include <string>

int main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str addr: " << &str << std::endl << "stringPTR addr: " << stringPTR << std::endl << "stringREF addr: " << &stringREF << std::endl << std::endl;
	std::cout << "str: " << str << std::endl << "stringPTR: " << *stringPTR << std::endl << "stringREF: " << stringREF << std::endl;
}