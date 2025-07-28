#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog& otherDog);
        Dog& operator=(const Dog& otherDog);
        virtual ~Dog();
        void makeSound() const;
        Brain* GetBrain() const;
};

#endif