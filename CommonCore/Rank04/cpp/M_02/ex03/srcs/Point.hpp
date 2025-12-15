#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>

class Point {
private:
	const int _x;
	const int _y;
public:
	Point();
	Point(const int x, const int y);
	~Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	int	getX();
	int	getY();
};

bool 	bsp( Point const a, Point const b, Point const c, Point const point);
int	sign(Point a, Point b, Point c);

#endif