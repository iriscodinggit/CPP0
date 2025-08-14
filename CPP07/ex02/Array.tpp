#include "Array.hpp"
#include <iostream>
#include <exception>

template<typename T>
Array<T>::Array() : _array(NULL), _length(0){}

template<typename T>
Array<T>::Array(unsigned int length) : _array(new T[length]()), _length(length){} //el () después de [length]() indica que va a inicializar a todos a 0

template<typename T>
Array<T>::Array(const Array& otherArray)
{
    this->_array = new T[otherArray._length]();
    for(unsigned int i = 0; i < otherArray._length; i++)
        this->_array[i] = otherArray._array[i];
    this->_length = otherArray._length;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& otherArray)
{
    if(this != &otherArray)
    {
        delete[] this->_array; //we delete because we are going to pass a whole new array and we need to delete the memory that he was already pointing to to avoid leaks
        this->_array = new T[otherArray._length];
        for(unsigned int i = 0; i < otherArray._length; i++)
            this->_array[i] = otherArray._array[i];
        this->_length = otherArray._length;
    }
    return(*this);
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template<typename T>
unsigned int Array<T>::size() 
{
    return(_length);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= _length)
        throw(std::out_of_range("❌ That element is not valid!"));
    return(_array[index]);
}