#include "../headers/Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::Cat(const Cat& otherCat) : Animal(otherCat) //we add the animal part, because to make a deep copy, we want to copu the basic behaviour from the animal part and then the cat specific parts
{
    std::cout << "Copy constructor for Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& otherCat)
{
    if (this != &otherCat)
    {
        type = otherCat.type;
        std::cout << "Assignment operator for Cat called" << std::endl;
    }
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Destructor for Cat called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "😸 Meow!" << std::endl;
}