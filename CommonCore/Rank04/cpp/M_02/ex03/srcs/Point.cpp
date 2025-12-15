#include "Point.hpp"

Point::Point() : _x(0), _y(0){
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const int x, const int y) : _x(x), _y(y){
	//std::cout << "Int constructor called" << std::endl;
}

Point::~Point(){
	//std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y){
	//std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	//std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

int	Point::getX(){
	return _x;
}

int	Point::getY(){
	return _y;
}
