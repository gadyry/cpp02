#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private :

	int rawBits;
	static const int fractionBits;

public :

   // Constructors
	Fixed();					// Default constructor
	Fixed(const int nbr);		// Integer constructor
	Fixed(const float nbr);		// Float constructor
	Fixed(const Fixed &other);	// Copy constructor

	// Destructor
	~Fixed();

	// Assignment operator
	Fixed &operator=(const Fixed &other);

	// Getter / Setter
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Conversion functions
	int	toInt( void ) const;
	float	toFloat( void ) const;

	// Comparison operators
	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	// Increment / Decrement operators
	Fixed&	operator++();    // Pre-increment
	Fixed	operator++(int); // Post-increment
	Fixed&	operator--();    // Pre-decrement
	Fixed	operator--(int); // Post-decrement

	// Static min/max functions
	static Fixed&		min(Fixed &a, Fixed &b);
	static const Fixed&	min(const Fixed &a, const Fixed &b);
	static Fixed&		max(Fixed &a, Fixed &b);
	static const Fixed&	max(const Fixed &a, const Fixed &b);

};

std::ostream&	operator<<(std::ostream &os, const Fixed &f);

#endif
