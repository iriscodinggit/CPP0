#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& otherCat);
    WrongCat& operator=(const WrongCat& otherCat);
    ~WrongCat();
    void makeSound() const;
};

#endif