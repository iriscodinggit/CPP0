#include "../headers/Cat.hpp"
#include "../headers/Brain.hpp"

Cat::Cat() : _brain(new Brain())
{
    type = "Cat";
    std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::Cat(const Cat& otherCat) : Animal(otherCat), _brain(new Brain(*otherCat._brain)) //we add the animal part, because to make a deep copy, we want to copu the basic behaviour from the animal part and then the cat specific parts
{
    std::cout << "Copy constructor for Cat called" << std::endl;
}

Cat& Cat::operator=(const Cat& otherCat)
{
    std::cout << "Assignment operator for Cat called" << std::endl;
    if (this != &otherCat)
    {
        Animal::operator=(otherCat); //first copy the animal part
        if (_brain)
            delete _brain; //important to delete the previous one in case there was already a brain
        _brain = new Brain(*otherCat._brain); //for a deep copy, we must not simply copy the pointer, but create a whole new brain with new
    }
    return(*this);
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Destructor for Cat called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "😸 Meow!" << std::endl;
}

Brain* Cat::GetBrain() const
{
    return (_brain);
}