#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

//i don't need to include the variable "type" here because it's already inherited from protected from Animal.hpp
class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat& otherCat);
        Cat& operator=(const Cat& otherCat);
        virtual ~Cat();
        void    makeSound() const;
        Brain* GetBrain() const;
};

#endif