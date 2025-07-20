#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a); //copy constructor (creates a new object based on a)
    Fixed c;

    c = b; //assignment operator (doesn't create a new object, just assigns a value on an already existing one)

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return (0);
}