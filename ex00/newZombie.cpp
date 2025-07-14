#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *heap_zombie;
    
    heap_zombie = new Zombie(name); //como malloc pero te ahorras hacer, por ejemplo, si quieres crear un array de 5 ints: (int *)malloc(5 * sizeof(int))
    return(heap_zombie);
}