#include "ScalarConverter.hpp"
//buscar librerias: size, is it from the standard library? if not, it's not think its not allowed

bool    isChar(std::string value)
{
    if (value.size() == 1 && !isdigit(value[0]))
        return(true);
    return(false);
}

bool    isInt(std::string value)
{
    for(int i = 0; value[i]; i++)
    {
        if(!isdigit(value[i]))
        {
            if(i == 0 && (value[i] == '+' || value[i] == '-'))
                continue; //continue skips to the next iteration without exiting the for loop, while break exits the loop entirely
            else
                return(false);
        }
    }
    return(true);
}

bool    isFloat(std::string value)
{
    int dotDetected = 0;

    if(value[value.size() - 1] != 'f') //checks the last char (not counting null char)
        return (false);
    for(long unsigned i = 0; i < value.size() - 1; i++) //-1 cause we don't want to check if 'f' is a digit, which is the last char
    {
        if(!isdigit(value[i])) //if it's not a digit, check if it's a sign or dot
        {
            if(i == 0 && (value[i] == '+' || value[i] == '-'))
                continue;
            else if(value[i] == '.' && !dotDetected)
            {
                dotDetected = true;
                continue;
            }
            else
                return(false);
        }
    }
    return(true);
}

bool    isDouble(std::string value)
{
    int dotDetected = 0;

    for(long unsigned int i = 0; i < value.size() - 1; i++) //-1 cause we don't want to check if 'f' is a digit, which is the last char
    {
        if(!isdigit(value[i])) //if it's not a digit, check if it's a sign or dot
        {
            if(i == 0 && (value[i] == '+' || value[i] == '-'))
                continue;
            else if(value[i] == '.' && !dotDetected)
            {
                dotDetected = true;
                continue;
            }
            else
                return(false);
        }
    }
    return(true);
}

int    isSpecial(std::string value)
{
    if(value == "+inff" || value == "-inff" || value == "nanf")
        return(3);
    else if (value == "+inf" || value == "-inf" || value == "nan")
        return(4);
    return (0);
}