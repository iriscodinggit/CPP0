#include "Span.hpp"
//try throw exception if too large //4294967295

int main()
{
    try
    {
        Span vector = Span(5);
        vector.addNumber(6);
        vector.addNumber(3);
        vector.addNumber(17);
        vector.addNumber(9);
        vector.addNumber(11);
        //vector.addNumber(15); //throw exception

        std::cout << "⭐ The shortest span is: " << vector.shortestSpan() << std::endl;
        std::cout << "⭐ The longest span is: " << vector.longestSpan() << std::endl;
    }
    catch(std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    
    try
    {
        std::vector<int> bigVector(10000);
        for (int i = 0; i < 10000; i++)
            bigVector[i] = i;

        Span bigSpan(10500);
        bigSpan.addNumbers(bigVector.begin(), bigVector.end());  // adds all 10000 values

        std::cout << "⭐ The shortest span is: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "⭐ The longest span is: " << bigSpan.longestSpan() << std::endl;
    }
    catch(std::exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    return (0);
}