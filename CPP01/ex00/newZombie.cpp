#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *heapZombie;
    
    heapZombie = new Zombie(name); //como malloc pero te ahorras hacer, por ejemplo, si quieres crear un array de 5 ints: (int *)malloc(5 * sizeof(int))
    return(heapZombie);
}