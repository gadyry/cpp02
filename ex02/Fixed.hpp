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

	Fixed(); // constractor
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed( const Fixed &other); // copy constractor
	Fixed& operator=(const Fixed& other);
	~Fixed(); // Destructor

	//Methods :
	int getRawBits(void) const;
	void setRawBits(int const raw);

	int	toInt( void ) const;
	float	toFloat( void ) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &f);

#endif