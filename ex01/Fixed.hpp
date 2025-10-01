/*

+----------------------------------+
|              Fixed              |
+----------------------------------+
| - _rawBits : int                |
| - _fractionalBits : const int = 8 (static) |
+----------------------------------+
| + Fixed()                       |
| + Fixed(const int n)            |
| + Fixed(const float n)          |
| + Fixed(const Fixed &other)     |
| + operator=(const Fixed &other) : Fixed& |
| + ~Fixed()                      |
| + getRawBits() const : int      |
| + setRawBits(raw : int) : void  |
| + toInt() const : int           |
| + toFloat() const : float       |
+----------------------------------+
| + operator<<(os : ostream&, f : Fixed&) : ostream& (friend) |
+----------------------------------+


*/

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
private :

    int rawBits;
    static const int fractionBits = 8;

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

    int toInt( void ) const;
    float   toFloat( void ) const;
};

#endif
