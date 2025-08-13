
#include "iter.hpp"

struct Bank //this struct is for my tests
{
    int money;

    Bank operator++(int) //dummy to know that it's i++ and not ++i
    {
        Bank oldBank = *this;
        ++money;
        return oldBank;
    }
};

std::ostream& operator<<(std::ostream& outputStream, const Bank& Bank)
{
    outputStream << "Money in the bank: " << Bank.money;
    return outputStream;
}

template<typename T>
void    printArray(T* array, int length)
{
    for(int i = 0; i < length; i++)
        std::cout << array[i] << std::endl;
}

template<typename T>
void increase(T& value)
{
    value++;
}

int main( void ) 
{
    char Chars[] = {'a', 'b', 'c', 'd', 'e' ,'f'};
    int Ints[] = {0, 2, 4, 6}; //try with max int exactly and one less?
    Bank Banks[] = {0, 1000000}; //what if it has two variables? do i need to add their names?

    std::cout << "🔤 Chars:" << std::endl;
    printArray(Chars, 6);
    std::cout << std::endl;
    iter(Chars, 6, increase);
    printArray(Chars, 6);
    std::cout << std::endl;

    std::cout << "🔟 Ints:" << std::endl;
    printArray(Ints, 4);
    std::cout << std::endl;
    iter(Ints, 4, increase);
    printArray(Ints, 4);
    std::cout << std::endl;

    std::cout << "🔟 Bank structs:" << std::endl;
    printArray(Banks, 2);
    std::cout << std::endl;
    iter(Banks, 4, increase);
    printArray(Banks, 2);
    return (0);
}