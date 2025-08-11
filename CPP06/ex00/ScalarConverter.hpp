#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONEVERTER_HPP

//USE LIMITS
#include <iostream>
#include <math.h> //strtof, strtod...
#include <limits>
#include <string>

class ScalarConverter
{
    private: // i have to make them private to make them not instantiable as the subject requires
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter);
        ~ScalarConverter();
    public:
        static void convert(std::string value);
};

//check type
bool    isChar(std::string value);
bool    isInt(std::string value);
bool    isFloat(std::string value);
bool    isDouble(std::string value);
int    isSpecial(std::string value);

//parse ranges

void charParse(char c);
void intParse(long i);
void floatParse(float f);
void doubleParse(double d);

#endif