#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib> //rand and srand
#include <ctime> //time(NULL)
#include <exception>

template<typename T>
class Array
{
    private:
            T               *_array;
            unsigned int    _length;
    public:
            Array();
            Array(unsigned int n);
            Array(const Array& otherArray);
            Array& operator=(const Array& otherArray);
            ~Array();
            T& operator[](unsigned int index); //?fir new[]?  or for accesing elements
            unsigned int size(); //getter getSize, to be able to call it on const arrays it must be const
};

#include "Array.tpp"

#endif
 