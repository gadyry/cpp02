#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private :

    int rawBits;
    static const int fractionBits = 8;

public :

    Fixed(); // constractor 
    Fixed( const Fixed &other); // copy constractor
    Fixed& operator=(const Fixed& other);
    ~Fixed(); // Destructor

    //Methods :
    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif

/*
Class Diag of ex00 : 

+-------------------------------+
|            Fixed             |
+-------------------------------+
| - _rawBits : int             |
| - _fractionalBits : const int (static) = 8 |
+-------------------------------+
| + Fixed()                    |
| + Fixed(const Fixed &other)  |
| + operator=(const Fixed &other) : Fixed& |
| + ~Fixed()                   |
| + getRawBits() const : int   |
| + setRawBits(raw : int) : void |
+-------------------------------+

*/