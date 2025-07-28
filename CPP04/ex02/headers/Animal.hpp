#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream> //cout input output stream

class Animal
{
    protected:
                std::string type;
    public:
                Animal();
                Animal(const Animal& otherAnimal);
                Animal& operator=(const Animal& otherAnimal);
                virtual ~Animal(); //siempre que haya al menos una función virtual (en este caso make sound) tiene que haber un destructor virtual. para asegurarte de que primero llama al destructor de dog y luego al de animal
                virtual void    makeSound() const; //es virtual porque no queremos que los hijos digan "animal made a sound", sino que lo overwritee por meow, woof.etc
                std::string     getType() const;
};

#endif