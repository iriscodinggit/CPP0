#include "../headers/Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default constructor for Animal called" << std::endl;
}

Animal::Animal(const Animal& otherAnimal)
{
    type = otherAnimal.type; //this is taken from the cpp of the other classes, since they inherited "type" from protected from Animal.hpp
    std::cout << "Copy constructor for Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& otherAnimal)
{
    if (this != &otherAnimal)
    {
        type = otherAnimal.type;
        std::cout << "Assignment operator for Animal called" << std::endl;
    }
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Destructor for Animal called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal is making a sound" << std::endl;
}

std::string Animal::getType() const
{
    return(type);
}