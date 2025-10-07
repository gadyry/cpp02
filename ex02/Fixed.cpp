#include "Fixed.hpp"

const int Fixed::fractionBits = 8;

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Integer constructor called" << std::endl;
	this->rawBits = nbr << this->fractionBits;// 2⁸ = 256
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(nbr * (1 << this->fractionBits));
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;

	// this->rawBits = other.rawBits;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->rawBits = other.rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
	Fixed	fixed;

	fixed.rawBits = this->rawBits + other.rawBits;
	return (fixed);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	fixed;

	fixed.rawBits = this->rawBits - other.rawBits;
	return (fixed);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	fixed;

	/*
		Each rawBits is already scaled by 2^fractionBits.
		So rawBits * rawBits is scaled by 2^(2*fractionBits).
		We must divide by 2^fractionBits once to fix the scale.
	*/
	fixed.rawBits = (this->rawBits * other.rawBits) >> this->fractionBits;
	return (fixed);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	fixed;

	if (other.rawBits != 0)
		fixed.rawBits = this->rawBits / other.rawBits;
	else
		std::cerr << "Error: division by zero" << std::endl;

	return (fixed);
}

// Increment / Decrement operators :

Fixed&	Fixed::operator++()    // Pre-increment
{
	
}

Fixed	Fixed::operator++(int) // Post-increment
{

}

Fixed&	Fixed::operator--()    // Pre-decrement
{

}

Fixed	Fixed::operator--(int) // Post-decrement
{

}



std::ostream& operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}
