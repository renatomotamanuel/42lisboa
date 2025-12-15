#include "Fixed.hpp"

int	main (void){
	Fixed a;
	std::cout << a.getRawBits() << std::endl;
	a.setRawBits(3);
	Fixed b ( a );
	Fixed c;

	c = b;

	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}