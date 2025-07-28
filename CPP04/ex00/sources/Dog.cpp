#include "../headers/Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::Dog(const Dog& otherDog) : Animal(otherDog) //we add the animal part, because to make a deep copy, we want to copu the basic behaviour from the animal part and then the Dog specific parts
{
    std::cout << "Copy constructor for Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& otherDog)
{
    if (this != &otherDog)
    {
        type = otherDog.type;
        std::cout << "Assignment operator for Dog called" << std::endl;
    }
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Destructor for Dog called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Woof!" << std::endl;
}