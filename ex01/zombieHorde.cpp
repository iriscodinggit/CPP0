#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string baseName )
{
    Zombie *zombieGang = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        std::stringstream concatenate;
        concatenate << baseName << "_" << (i + 1);
        zombieGang[i].setName(concatenate.str()); //.str() returns the final concatenated string
    }
    return(zombieGang);
}