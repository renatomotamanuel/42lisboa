#include "Point.hpp"

int	sign(Point a, Point b, Point c){
	return ((a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY()));
}

bool helper(Point a, Point b, Point c, Point point){
	return ((point.getX() == a.getX() && point.getY() == a.getY()) ||
        (point.getX() == b.getX() && point.getY() == b.getY()) ||
        (point.getX() == c.getX() && point.getY() == c.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int		has_neg;
	int		has_pos;
	int	d1;
	int	d2;
	int	d3;

	if(helper(a, b, c, point))
		return false;
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	if(!d1 || !d2 || !d3)
		return false;
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!(has_neg && has_pos));
}

