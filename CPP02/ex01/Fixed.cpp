#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _shiftedValue = 0;
}

Fixed::Fixed(const int  originalNumberI) //converts int to fixed point
{
    std::cout << "Int constructor called" << std::endl; 
    _shiftedValue = originalNumberI * (1 << _fractionBits); // 1 << 8 is = 256 (because you move the 1 to the first place) 0000 0001 -> 00000001 00000000. So if the original number is 5, it would be 5 * 256 = 1280
}

Fixed::Fixed(const float  originalNumberF)
{
    std::cout << "Float constructor called" << std::endl; 
    _shiftedValue = roundf(originalNumberF * (1 << _fractionBits)); //e.g: 12.345 * 256 = 3160.32 //roundf is used in case the numbner has decimals like now (.32). It just rounds it to 3160 to reduce truncation errors (in this case both are setting it to 3160, but if we had 9.9, one would truncate it to 9 and another with roundf 10). if u remove it, you still get a pretty close result but a bit less. So now we shifted the number to preserve the fractional part and then we want it back, we just shift it back again (3160 / 256 = 12.34375) (pretty close) (floats always lose a bit of precision like 1 / 3 = 0.333)
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
        _shiftedValue = originalObject.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void)const
{
    return (_shiftedValue);
}

void Fixed::setRawBits(int const shiftedValue)
{
    _shiftedValue = shiftedValue;
}

int Fixed::toInt(void)const
{
    int return_value = _shiftedValue / (1 << _fractionBits);
    return (return_value);
}

float Fixed::toFloat(void) const
{
    float return_value = (float)_shiftedValue / (1 << _fractionBits); //we need to cast to (float) because if we divide int / int, C++ trucantes and doesn't keep decimals, so for example 5 / 2 would get 2 instead of 2.5. But if AT LEAST ONE value is float, it will keep the decimal and give 2.5
    return(return_value);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& originalObject)
{
    outputStream << originalObject.toFloat(); //tells the compiler how to print this << a (i.e.: go to the .toFloat function and print that value!)
    return (outputStream); //<< always returns a ref to the outputstream so that it's possible to chain multiple << in a single call
}