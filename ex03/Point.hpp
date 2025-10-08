#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	// constructor
	Point();

	// Constructor with two float values
	Point(const float xVal, const float yVal);

	// Copy constructor
	Point(const Point &other);

	// Copy assignment operator
	Point &operator=(const Point &other);

	// Destructor
	~Point();

	// Getters 
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif
