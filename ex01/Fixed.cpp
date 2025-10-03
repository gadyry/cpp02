#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Integer constructor called" << std::endl;
    this->rawBits = nbr << this->fractionalBits;
}

Fixed::Fixed(const int float)
{
    std::cout << "Float constructor called" << std::endl;
    this->rawBits = roundf(nbr * (1 << this->fractionalBits));
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->rawBits = other.rawBits;

	/* Also We can do this instruction : if copy assignement is already implemented !!
		*this = other;
	*/
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
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
