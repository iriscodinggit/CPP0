#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONEVERTER_HPP

#include <iostream>
#include <cstdlib> //for atof, atoi...
#include <math.h> //for inf, nan?
#include <limits>

class ScalarConverter
{
    private: // i have TO MAKE THEM PRIVATE to make it NON INSTANTIABLE
        ScalarConverter(/* args */);
        ~ScalarConverter();
    public:
        static void convert(std::string value);
};

#endif
