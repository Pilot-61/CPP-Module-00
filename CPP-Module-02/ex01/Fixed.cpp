#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) : fixedPointValue(value << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(float value) : fixedPointValue(int(roundf(value * (1 << fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedPointValue(other.fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}


void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}


float Fixed::toFloat() const
{
    return ((float) this->fixedPointValue / (1 << fractionalBits));
}


int Fixed::toInt() const
{
    return ((int) roundf(this->fixedPointValue / (1 << fractionalBits)));
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}


