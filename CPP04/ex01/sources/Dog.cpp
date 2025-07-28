#include "../headers/Dog.hpp"
#include "../headers/Brain.hpp"

Dog::Dog() : _brain(new Brain())
{
    type = "Dog";
    std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::Dog(const Dog& otherDog) : Animal(otherDog), _brain(new Brain(*otherDog._brain)) //we add the animal part, because to make a deep copy, we want to copu the basic behaviour from the animal part and then the Dog specific parts
{
    std::cout << "Copy constructor for Dog called" << std::endl;
}

Dog& Dog::operator=(const Dog& otherDog)
{
    std::cout << "Assignment operator for Dog called" << std::endl;
    if (this != &otherDog)
    {
        Animal::operator=(otherDog); //first we copy the animal part
        if (_brain) //we delete the previous brain in case there was one to avoid leaks
            delete _brain;
        _brain = new Brain(*otherDog._brain); //we do a deep copy by creating a whole new brain with new instead of just copying the pointer
    }
    return(*this);
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Destructor for Dog called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Woof!" << std::endl;
}

Brain* Dog::GetBrain() const {
    return (_brain);
}