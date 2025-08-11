#include "ScalarConverter.hpp"

int checkType(std::string value)
{
    if (value.empty())
        return(0);
    if(isChar(value))
        return(1);
    else if(isInt(value))
        return(2);
    else if(isFloat(value) || isSpecial(value) == 3)
        return(3);
    else if(isDouble(value) || isSpecial(value) == 4)
        return(4);
    else
        return(0);
}

void castParseAndDisplay(int typeCase, std::string value)
{
    switch(typeCase)
    {
        case 1: //char
        {
            char c = static_cast<char>(value[0]);
            charParse(c);
            intParse(static_cast<int>(c));
            floatParse(static_cast<float>(c));
            doubleParse(static_cast<double>(c));
            break;
        }
        case 2: //int
        {
            long i = strtol(value.c_str(), NULL, 10); //we convert to double instead of to int to check overflows larger than max int and min int. we convert value to const string with (c.str because strtod needs a const). NULL is because we dont need a pointer and 10 because we use base 10
            charParse(static_cast<char>(i));
            intParse(i);
            floatParse(static_cast<float>(i));
            doubleParse(static_cast<double>(i));
            break;
        }
        case 3: //float
        {
            float f = strtof(value.c_str(), NULL); //we convert to double instead of to int to check overflows larger than max int and min int. we convert value to const string with (c.str because strtod needs a const). NULL is because we dont need a pointer
            charParse(static_cast<char>(f));
            intParse(static_cast<int>(f));
            floatParse(f);
            doubleParse(static_cast<double>(f));
            break;
        }
        case 4: //double
        {
            double d = strtod(value.c_str(), NULL); //we convert to double instead of to int to check overflows larger than max int and min int. we convert value to const string with (c.str because strtod needs a const). NULL is because we dont need a pointer
            charParse(static_cast<char>(d));
            intParse(static_cast<int>(d));
            floatParse(static_cast<float>(d));
            doubleParse(d);
            break;
        }
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}

//check type, check range, convert to its type, convert to the other 3 types, display in this order: char, int, float, double 
void    ScalarConverter::convert(std::string value) //this is static, which means that it doesn't belong to any object, u can call it without instantiating objects
{
    int typeCase;
    typeCase = checkType(value);
    castParseAndDisplay(typeCase, value); //switch that takes a number and casts, then display
}

//TRY EMPTY STRINGS
//any other overflows apart from char 0-127 (0-31 are not printable), max/min int, inf to int, nan to int/char? Inf can be converted to double and float
//only decimal notatiion: (doesnt mean decimals), means we just have to handle base 10 inputs, no hexadecimal, no octalm no scientifici notation
