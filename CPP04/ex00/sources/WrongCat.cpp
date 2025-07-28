#include "../headers/WrongCat.hpp"
#include "../headers/WrongAnimal.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "Default constructor for WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& otherCat) : WrongAnimal(otherCat) //we add the wronganimal part, because to make a deep copy, we want to copu the basic behaviour from the animal part and then the WrongCat specific parts
{
    std::cout << "Copy constructor for WrongCat called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& otherCat)
{
    if (this != &otherCat)
    {
        type = otherCat.type;
        std::cout << "Assignment operator for WrongCat called" << std::endl;
    }
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor for WrongCat called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "😸 Mmm..meee..meoo----LOST CONNECTION" << std::endl;
}