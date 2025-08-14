#include "easyfind.hpp"

void printVector(const std::vector<int>& intVector)
{
    for(unsigned long i = 0; i < intVector.size(); i++)
        std::cout << intVector[i] << std::endl;
}


int main(void) 
{
    try
    {
        std::cout << "🧙 Generating an int vector..." << std::endl << std::endl;
        std::vector<int> intVector; 
        intVector.push_back(100);
        intVector.push_back(200);
        intVector.push_back(300);
        intVector.push_back(400);
        intVector.push_back(500);
        std::vector<int>::const_iterator i = easyfind(intVector, 400);
        printVector(intVector);
        std::cout << std::endl << "Object has been found : " << *i << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }

    try
    {
        std::vector<int> intVector; 
        intVector.push_back(100);
        intVector.push_back(200);
        intVector.push_back(300);
        intVector.push_back(400);
        intVector.push_back(500);
        std::vector<int>::const_iterator i = easyfind(intVector, 600);
        printVector(intVector);
        std::cout << "Object has been found : " << *i << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << error.what() << std::endl;
    }
}