#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point a(15.0f, 0.0f);
	Point b(0.0f, 15.0f);
	Point c(15.0f, 15.0f);

	Point point(15.0f, 14.0f);
	if (!bsp(a, b, c, point))
		std::cout << "Point not inside the triangle" << std::endl;
	else
		std::cout << "Point inside the triangle" << std::endl;
    return 0;
}

