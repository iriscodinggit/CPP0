#include "ScalarConverter.hpp"

void    charParse(char c) //do i have to print the char between ''?
{
    if(c < 127 && c > 0)
    {
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl;
    }   
    else
        std::cout << "char: impossible" << std::endl;
}

void    intParse(long i)
{
    if (i > std::numeric_limits<int>::min() && i < std::numeric_limits<int>::max()) //same as doing < MAX_INT && > MIN_INT but this one makes all the limit checking equal throughot the types (char, double...etc)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: impossible"<< std::endl; 
}

void    floatParse(float f)
{
    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f > -std::numeric_limits<float>::max() && f < std::numeric_limits<float>::max()) //if the value is outside these ranges, it becomes infinity
    {
        if (f == floorf(f)) //floorf checks if it ends in .0 or has actual significant decimals like .1
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
        // Here you place all the conversion to other type // 
    }
    else
        std::cout << "float: impossible"<< std::endl; 
}

void    doubleParse(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << d << std::endl;
    else if (d > -std::numeric_limits<double>::max() && d < std::numeric_limits<double>::max()) //-max() is the most negative finite value
    {
        if (d == floor(d)) //floor checks if it ends in .0 or has actual significant decimals like .1
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    else
        std::cout << "double: impossible"<< std::endl; 
}