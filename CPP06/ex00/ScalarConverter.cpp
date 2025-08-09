#include "ScalarConverter.hpp"
//buscar librerias: size
void    ScalarConvert::convert(std::string value)
{
    if(value.size() == 1 && !isdigit(literal[0]))
    else
        std::cout << "Cannot display that conversion." << std::endl;
}

//any other overflows apart from char?
//why is the hpp function static?
//only decimal notatiion: (doesnt mean decimals), means we just have to handle base 10 inputs, no hexadecimal, no octalm no scientifici notation
//the class must not be instantiable so i make constructor private