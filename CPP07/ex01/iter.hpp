#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string.h> //for?

template<typename T>
void    iter(T * newArray, int length, void (*function)(T &))
{
    for(int i = 0; i < length; i++)
        function(newArray[i]);
}

#endif