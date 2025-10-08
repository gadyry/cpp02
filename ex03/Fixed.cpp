#include "Fixed.hpp"

const int Fixed::fractionBits = 8;

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(const int nbr)
{
	this->rawBits = nbr << this->fractionBits;// 2⁸ = 256
}

Fixed::Fixed(const float nbr)
{
	this->rawBits = roundf(nbr * (1 << this->fractionBits));
}


Fixed::Fixed(const Fixed& other)
{
	// this->rawBits = other.rawBits;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	this->rawBits = other.rawBits;
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

// Conversion functions : 

int	Fixed::toInt( void ) const
{
	return (this->rawBits >> this->fractionBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)(rawBits) / (1 << fractionBits));
}

// Comparison operators :

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->rawBits > other.rawBits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->rawBits < other.rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->rawBits <= other.rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->rawBits == other.rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->rawBits != other.rawBits);
}

// Arithmetic operators :

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
    if (other.toFloat() == 0)
    {
        std::cerr << "Error: division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement operators :

Fixed&	Fixed::operator++()    // Pre-increment
{
	this->rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) // Post-increment
{
	Fixed	tmp = *this;

	this->rawBits++;
	return (tmp);
}

Fixed&	Fixed::operator--()    // Pre-decrement
{
	this->rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) // Post-decrement
{
	Fixed	tmp = *this;

	this->rawBits--;
	return (tmp);
}

// Static min/max functions :

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}


std::ostream& operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
