#include "Point.hpp"


Point::Point() : x(0), y(0) {}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	// We cannot reassign const members
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
