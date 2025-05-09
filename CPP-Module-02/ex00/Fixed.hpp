#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fraBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);
    ~Fixed();

    int     getRawBits() const;
    void    setRawBits(int const raw);
};

#endif