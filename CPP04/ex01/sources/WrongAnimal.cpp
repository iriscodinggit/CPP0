#include "../headers/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& otherAnimal)
{
    type = otherAnimal.type; //this is taken from the cpp of the other classes, since they inherited "type" from protected from WrongAnimal.hpp
    std::cout << "Copy constructor for WrongAnimal called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& otherAnimal)
{
    if (this != &otherAnimal)
    {
        type = otherAnimal.type;
        std::cout << "Assignment operator for WrongAnimal called" << std::endl;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor for WrongAnimal called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal is making a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(type);
}