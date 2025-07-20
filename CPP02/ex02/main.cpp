#include "Fixed.hpp"
#include <iostream>

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); //multiplicas dos objetos de tipo fixed y pasas el resultado como argumento
    std::cout << a << std::endl;
    std::cout << ++a << std::endl; //why does it add 0.00390625? because 1 / 256 equals that number, which is the smallest step my fixed-point class can represent
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    /**my extra tests
    std::cout << "\n--- Extra Tests ---" << std::endl;
    Fixed c(Fixed(5) / Fixed(2));
    std::cout << "Division: " << c << std::endl;

    c = Fixed(5) + Fixed(2);
    std::cout << "Addition: " << c << std::endl;

    c = Fixed(5) - Fixed(2);
    std::cout << "Substraction: " << c << std::endl;

    //comparsion operator tests

    Fixed x(10);
    Fixed y(20);

    std::cout << "\n--- Comparison Tests ---" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl;
    std::cout << "x == y? " << (x == y) << std::endl;
    std::cout << "x != y? " << (x != y) << std::endl;
    std::cout << "x < y? " << (x < y) << std::endl;
    std::cout << "x <= y? " << (x <= y) << std::endl;
    std::cout << "x > y? " << (x > y) << std::endl;
    std::cout << "x >= y? " << (x >= y) << std::endl;

    // min test
    std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
    std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

    // Decrement tests
    std::cout << "\n--- Decrement Tests ---" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "--x: " << --x << std::endl;
    std::cout << "x--: " << x-- << std::endl;
    std::cout << "x after x--: " << x << std::endl;
    */
    return (0);
}