#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if(ac != 2)
        return std::cout << "Wrong usage." << std::endl, 0;
    return parse(av[1]);
}