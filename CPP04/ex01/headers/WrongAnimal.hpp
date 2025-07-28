#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class   WrongAnimal
{
    protected:
                std::string type;
    public:
                WrongAnimal();
                virtual ~WrongAnimal();
                WrongAnimal(const WrongAnimal& otherAnimal);
                WrongAnimal& operator=(const WrongAnimal& otherAnimal);
                virtual void makeSound() const;
                std::string getType() const;
};

#endif