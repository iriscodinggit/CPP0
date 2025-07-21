#include "Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    _shiftedValue = 0;
}

Fixed::Fixed(const int  originalNumberI)
{
    //std::cout << "Int constructor called" << std::endl; 
    _shiftedValue = originalNumberI * (1 << _fractionBits);
}

Fixed::Fixed(const float  originalNumberF)
{
    //std::cout << "Float constructor called" << std::endl; 
    _shiftedValue = roundf(originalNumberF * (1 << _fractionBits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &originalObject)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = originalObject;
}

Fixed& Fixed::operator=(const Fixed& originalObject)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &originalObject)
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
    float return_value = (float)_shiftedValue / (1 << _fractionBits);
    return(return_value);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& originalObject)
{
    outputStream << originalObject.toFloat();
    return (outputStream);
}

//Min & max

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a.getRawBits() > b.getRawBits())
        return(b);
    return(a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a.getRawBits() > b.getRawBits())
        return(b);
    return(a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a.getRawBits() < b.getRawBits())
        return(b);
    return(a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a.getRawBits() < b.getRawBits())
        return(b);
    return(a);
}

//New operator overloads

Fixed Fixed::operator++()
{
    this->_shiftedValue++;
    return(*this);
}

Fixed Fixed::operator--()
{
    this->_shiftedValue--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tempObject = *this;
    ++this->_shiftedValue;
    return (tempObject);
}

Fixed Fixed::operator--(int)
{
    Fixed tempObject = *this;
    --this->_shiftedValue;
    return(tempObject);
}

Fixed Fixed::operator+(const Fixed& otherObject)
{
    Fixed result;
    result._shiftedValue = this->_shiftedValue + otherObject._shiftedValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& otherObject)
{
    Fixed result;
    result._shiftedValue = this->_shiftedValue - otherObject._shiftedValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& otherObject) //analogía: milímetros y m^2
{
    Fixed result;
    result._shiftedValue = (this->_shiftedValue * otherObject._shiftedValue)  >> _fractionBits; //en mult y division hay que hacer un shifteo << porque ambos numeros ya estan escalados por 256 (solo hay que escalar una vez) entonces divides una vez con << para corregir.  //<< multiplicar y >> dividir
    return result;
}

Fixed Fixed::operator/(const Fixed& otherObject)
{
    Fixed result;
    result._shiftedValue = (this->_shiftedValue << _fractionBits)  / otherObject._shiftedValue; //mult primero el numerador para compensar
    return result;
}

//compare operators

bool Fixed::operator<(const Fixed& otherObject)
{
    return this->_shiftedValue < otherObject._shiftedValue;
}

bool Fixed::operator>(const Fixed& otherObject)
{
    return this->_shiftedValue > otherObject._shiftedValue;
}

bool Fixed::operator<=(const Fixed& otherObject)
{
    return this->_shiftedValue <= otherObject._shiftedValue;
}

bool Fixed::operator>=(const Fixed& otherObject)
{
    return this->_shiftedValue >= otherObject._shiftedValue;
}

bool Fixed::operator ==(const Fixed& otherObject)
{
    return this->_shiftedValue == otherObject._shiftedValue;
}

bool Fixed::operator !=(const Fixed& otherObject)
{
    return this->_shiftedValue < otherObject._shiftedValue;
}