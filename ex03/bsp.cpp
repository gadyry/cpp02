#include "Point.hpp"

static Fixed	triangleArea(Point  p1, Point p2, Point p3)
{
	Fixed area;

	Fixed	x1 = p1.getX();
	Fixed	y1 = p1.getY();

	Fixed 	x2 = p2.getX();
	Fixed 	y2 = p2.getY();

	Fixed 	x3 = p3.getX();
	Fixed	y3 = p3.getY();

	// calcul  determinant : A = | x1​(y2​−y3​)+ x2​(y3​−y1​)+ x3​(y1​−y2​) | / 2
	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ABC = triangleArea(a, b, c);
	Fixed	PBC = triangleArea(point, b, c);
	Fixed	APC = triangleArea(a, point, c);
	Fixed	ABP = triangleArea(a, b, point);

	Fixed	omega(0.0001f);
	Fixed sum;

	if (PBC <= omega || APC <= omega || ABP <= omega)
		return (false); // on edge or vertex

	sum = PBC + APC + ABP;
	if ((sum - ABC) > omega || (ABC - sum) > omega)
		return (false);
	return (true);
}
