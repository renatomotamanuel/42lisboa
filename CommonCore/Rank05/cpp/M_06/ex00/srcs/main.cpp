#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if(ac != 2)
        return std::cout << "Error" << std::endl, 1;
    else
        ScalarConverter::convert(av[1]);
}