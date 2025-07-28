#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

//i don't need to include the variable "type" here because it's already inherited from protected from Animal.hpp
class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& otherCat);
        Cat& operator=(const Cat& otherCat);
        virtual ~Cat();
        void    makeSound() const;
};

#endif