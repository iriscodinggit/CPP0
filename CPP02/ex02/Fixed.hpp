#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    private:
        int                 _shiftedValue; //the raw value (integer and decimals combined)
        static const int    _fractionBits = 8; //how many digits are used for the fractional value (after the point) //if you want more precision, you can change 8 for 16...but if you have more decimal bits, you'll have less integer bits and therefore bigger numbers will not be possible
    public:
        Fixed();
        Fixed(const int originalNumberI);
        Fixed(const float originalNumberF);
        Fixed(const Fixed &originalObject); //copy constructor (initialises and assign)
        ~Fixed();
        //new operators
        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        Fixed operator+(const Fixed &otherObject);
        Fixed operator-(const Fixed &otherObject);
        Fixed operator*(const Fixed &otherObject);
        Fixed operator/(const Fixed &otherObject);

        bool operator<(const Fixed &otherObject);
        bool operator>(const Fixed &otherObject);
        bool operator<=(const Fixed &otherObject);
        bool operator>=(const Fixed &otherObject);
        bool operator==(const Fixed &otherObject);
        bool operator!=(const Fixed &otherObject);
        //end of new operators
        Fixed&  operator=(const Fixed &originalObject); //assigment operator (does NOT initialise, cause the object already exists, just assigns (more efficient cause it's just one step))
        int     getRawBits(void) const; //const means that it's readonly, wont modify the value
        void    setRawBits(int const shiftedValue);
        float   toFloat(void) const; //converts fixed point to float
        int     toInt(void) const; //converts fixed point to int
        //new functions
        static Fixed& min(Fixed& objectA, Fixed& objectB); //these functions are static because they dont belong to a specific object, they belong to the class itself, so u don't need to call a specific object
        static const Fixed& min(const Fixed& objectA, const Fixed& objectB); //it's constant so you can't modify the objects (the reference can't be modified anyways, it means you cant modify the objects'es elements)
        static Fixed& max(Fixed& objectA, Fixed& objectB);
        static const Fixed& max(const Fixed& objectA, const Fixed& objectB);
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed &originalObject); //it gets called when u use the << operator + an output stream (like cout) + an object name. Ex: std::cout << myFixedObject;
//returns a reference to ostream (output stream) to chain calls (using multiple <<). A normal call like std::cout << "hi" << std::endl; ALWAYS returns a value per each <<, in this case std::cout per every <<. That's a value of type std::ostream&, that's why when we create our overload it also has to return an std::ostream& type too

#endif