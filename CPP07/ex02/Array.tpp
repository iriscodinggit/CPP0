#include <iostream>
#include <exception>

template<typename T>
Array<T>::Array() : _array(NULL), _len(0){}

template<typename T>
Array<T>::Array(unsigned int len) : _array(new T[len]()), _len(len){}

template<typename T>
Array<T>::Array(const Array& other)
{
    this->_array = new T[other._len]();
    for(unsigned int i = 0; i < other._len; i++)
        this->_array[i] = other._array[i];
    this->_len = other._len;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if(this != &other)
    {
        delete[] this->_array;
        this->_array = new T[other._len];
        for(unsigned int i = 0; i < other._len; i++)
            this->_array[i] = other._array[i];
        this->_len = other._len;
    }
    return(*this);
}

template<typename T>
inline Array<T>::~Array() { delete[] _array;};

template<typename T>
inline unsigned int Array<T>::size() {return(_len);};

template<typename T>
T& Array<T>::operator[](const unsigned int index)
{
    if(index >= _len)
        throw(std::out_of_range("Out of bounds\n"));
    return(_array[index]);
}