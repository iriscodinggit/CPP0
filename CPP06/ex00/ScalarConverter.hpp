#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONEVERTER_HPP

#include <iostream>
#include <cstdlib> //for atof, atoi...
#include <math.h> //for what?
#include <limits>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

class ScalarConverter
{
    private: // i have to make them private to make them not instantiable as the subject requires
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter&) = delete;
        ScalarConverter& operator=(const ScalarConverter) = delete;
        ~ScalarConverter() = delete;
    public:
        static void convert(std::string value);
};

void    convertChar(std::string value);
void    convertInt(std::string value);
void    convertFloat(std::string value);
void    convertDouble(std::string value);
void    convertSpecial(std::string value);
#endif
