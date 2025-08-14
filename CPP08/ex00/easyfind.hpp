#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm> //for find

template<typename T>
typename T::const_iterator easyfind(const T& vector, int searchValue)
{
    typename T::const_iterator i; //const iterator is a default operator that can just read, but not write

    i = std::find(vector.begin(), vector.end(), searchValue);
    if(i == vector.end())
        throw(std::out_of_range("The value has not been found!"));
    return (i);
}

#endif