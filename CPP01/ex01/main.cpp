#include "Zombie.hpp"

int main(void)
{
    int N = 500000;
    std::string name = "🧟 Minion";
    Zombie *zombieGang;

    if (N <= 0 || N >= 1000000)
    {
        std::cerr << "🧟 The number of zombies must be higher than 0 and smaller than 1000000." << std::endl;
        return (1);
    }
    zombieGang = zombieHorde(N, name);
    for(int i = 0; i < 5; i++)
        zombieGang[i].announce();
    delete[] zombieGang;
    return (0);
}