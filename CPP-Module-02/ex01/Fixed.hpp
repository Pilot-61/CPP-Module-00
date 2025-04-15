#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed &other);
    ~Fixed();
    
    Fixed &operator=(const Fixed &other);

    int     getRawBits() const;
    void    setRawBits(int const raw);
    float   toFloat() const;
    int     toInt() const;
};

#endif
