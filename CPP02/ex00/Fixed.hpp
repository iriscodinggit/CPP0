#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 _rawValue; //the raw value (integer and decimals combined)
        static const int    _fractionBits = 8; //how many digits are used for the fractional value (after the point)
    public:
        Fixed();
        Fixed(const Fixed &originalObject); //copy constructor (initialises and assign)
        ~Fixed();
        Fixed&  operator=(const Fixed &originalObject); //assigment operator (does NOT initialise, cause the object already exists, just assigns (more efficient cause it's just one step))
        int     getRawBits(void) const; //const means that it's readonly, wont modify the value
        void    setRawBits(int const rawValue);
};

#endif