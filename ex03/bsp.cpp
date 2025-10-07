#include "Point.hpp"

static Fixed	triangleArea(Point  p1, Point p2, Point p3)
{
	Fixed area;

	Fixed x1 = p1.getX();
	Fixed y1 = p1.getY();
	Fixed x2 = p2.getX();
	Fixed y2 = p2.getY();
	Fixed x3 = p3.getX();
	Fixed y3 = p3.getY();

	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ABC;
	Fixed	PAC;
	Fixed	PBC;
	Fixed	PAB;
}
