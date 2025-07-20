#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _rawValue = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &originalObject)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = originalObject; //b = a
}

Fixed& Fixed::operator=(const Fixed& originalObject)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &originalObject) //makes sure that its not a = a (self assignment, which could cause bugs someties)
        _rawValue = originalObject.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawValue);
}

void Fixed::setRawBits(int const rawValue)
{
    _rawValue = rawValue;
}